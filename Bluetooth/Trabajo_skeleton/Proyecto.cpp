#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "SerialClass/SerialClass.h" // Biblioteca para acceder al puerto serie
#define Tamano_com 200

int main()
{
	Serial* Arduino;
	char puerto[] = "COM5";
	int bytesRecibidos;
	int angle;
	char BufferSalida[Tamano_com];
	char BufferEntrada[Tamano_com];
	Arduino = new Serial((char*)puerto); // Crea conexión lógica con Arduino

		if (Arduino->IsConnected())
			printf("Conectado a Arduino");
		BufferSalida[1] = '\0';

		while (Arduino->IsConnected())
		{
			

			do
			{	
				printf("Angulo:");
				scanf_s("%d", &angle);
				printf("Enviando %d ", angle);
				//BufferSalida[0] = angle;
				switch (angle)
				{
					case 0:
						BufferSalida[0] = '0';
					break;
					case 90:
						BufferSalida[0] = '1';
					break;
				default:
					break;
				}
				printf("también %d\n", BufferSalida);

				Arduino->WriteData(BufferSalida, strlen(BufferSalida));

				bytesRecibidos = Arduino->ReadData(BufferEntrada, sizeof(char) * Tamano_com);

				if (bytesRecibidos != -1) // Lectura de mensaje desde el puerto
				{
					BufferEntrada[bytesRecibidos-1] = '\0';
					printf("Recibidos %d bytes: %s\n", bytesRecibidos, BufferEntrada);
				}
				else {
					printf("No se ha recibido nada\n");
				}
				Sleep(1000);

			} while (BufferEntrada != "SERVO CAMBIADO\0");

			Sleep(1000);
		}
}