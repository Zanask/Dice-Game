// Importamos las librerias necesarias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// Declaramos el rand y las variables 
	srand((unsigned)time(NULL));
	int j = 5;	// Cantidad de dados iniciales
	int x = 0;	//Variable para salir del bucle de partida de cada jugador
	int dado[5];	// Array de los 5 numeros que mostramos por pantalla
	int n1;		// Variable para la opcion del switch
	int puntos = 0; 	// Inicializamos los puntos base a 0
	int puntuacionmaxima = 0;	// Fijamos puntuaciones maximas a 0

	// Empieza el Juego
	// Menu principal
	printf("\nBienvenido a Drop Dead, un entretenido juego donde la suerte lo es todo, te atreves a jugar?\n\n");
start:
	printf("1. Jugar\n");
	printf("2. Puntuacion mas alta\n");
	printf("3. Reiniciar puntuaciones\n");
	printf("0. Salir\n");
	printf("\nEscoje una opcion: ");
	scanf("%d", &n1);

	switch (n1)
	{
	case 1:
		// Juego principal
		printf("\nHas querido jugar");
		// g = Jugador
		for (int g = 1; g <= 2; g++)
		{
			x = 0; // Volvemos a inicializarlas para cada jugador
			j = 5;	// Volvemos a inicializarlas para cada jugador
			puntos = 0; // Volvemos a inicializarlas para cada jugador
			printf("\n\nTurno del jugador %d", g);

			// Partida de cada jugador

			while (x < 1)
			{
				printf("\n\nTirando los dados...\n");
				system("PAUSE");
				printf("Los dados son: ");

				// Randomizamos los dados y los metemos en la array

				for (int i = 0; i < j; i++)
				{
					dado[i] = rand() % 6 + 1;
					printf("  %d  ", dado[i]);
				}
				int j2; // Declaramos copia de dados
				j2 = j;	// Clonamos la cantidad de dados

				// Empezamos el for con los dados iniciales

				for (int i = 0; i < j2; i++)
				{
					// Si es igual a 2 o 5, resta un dado
					if (dado[i] == 2 || dado[i] == 5)
					{
						j--;
					}
					// Si no, suma los puntos
					else
					{
						puntos = puntos + dado[i];
					}
					// Si no quedan dados, acaba el turno
					if (j == 0)
					{
						x++;
					}
				}
				printf("\n\nCambio de ronda, resultado total: %d", puntos);
				if (puntos > puntuacionmaxima)
				{
					puntuacionmaxima = puntos;
				}
			}
			printf("\n\n\nResultado total del jugador %d:  %d", g, puntos);
			printf("\n\n\n");
		}
		printf("\n\n----------------------------------------------------------------------------\n");
		goto start;
		break;
	case 2:
		// Muestra la puntuacion mas alta desde que se ha iniciado el programa
		printf("\nMostrando ultimas partidas\n");
		printf("\nPuntuacion total mas alta: %d", puntuacionmaxima);
		printf("\n\n----------------------------------------------------------------------------\n");
		goto start;
		break;
	case 3:
		// Fija todas las puntuaciones a 0
		printf("\nReiniciando puntuaciones...\n");
		puntuacionmaxima = 0;
		printf("\nPuntuaciones fijadas a cero\n");
		printf("\n\n----------------------------------------------------------------------------\n");
		goto start;
		break;
	default:
		// Acaba el programa
		printf("\nHas elegido la rendicion...\n");
		system("PAUSE");
		exit(-1);
		break;
	}

	printf("\n");
	system("PAUSE");
	return 0;
}