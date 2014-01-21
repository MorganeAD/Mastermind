#define LINUX

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"

#ifdef LINUX
    #define CHARACTER1 "é"
	#define CHARACTER2 "è"
	#define CHARACTER3 "ê"
	#define CHARACTER4 "à"
	#define CLEAR() system("clear");
#endif
#ifdef WINDOWS
    #define CHARACTER1 "e"
	#define CHARACTER2 "e"
	#define CHARACTER3 "e"
	#define CHARACTER4 "a"
	#define CLEAR() system("cls");
#endif



int main(int argc, char const *argv[])
{
	CLEAR()
	int screen = 4;

	do
		{
		Title();

		if (screen == 4)
		{
			printf("1. 1 Joueur\n2. 2 Joueurs\n3. R%sgles\n", CHARACTER1);
		}

		if (screen == 1 || screen == 2)
		{
			// INITIALISATION DU JEU 1 JOUEUR

			char unknownColors[5] = {0};
			unknownColors[5] = '\0';
			int i = 0;

			if (screen == 1)
			{
				srand(time(NULL));
				int drawnColor = 0;

				for (i = 0; i < 4; ++i)
				{
					do
					{
						drawnColor = randomColors(65, 72);
					} while (checkColorTab(drawnColor, unknownColors, 4));
					unknownColors[i] = drawnColor;
				}
				printf("Proposez 4 couleurs de votre choix pour d%scouvrir la combinaison myst%sre:\n", CHARACTER1, CHARACTER2);
			}

			// INITIALISATION DU JEU 2 JOUEURS

			if (screen == 2)
			{
				printf("Joueur 1, proposez 4 couleurs myst%sres à faire chercher %s Joueur 2:\n", CHARACTER2, CHARACTER4);
				do
				{
					unknownColors[4] = 1;
					scanf("%s", unknownColors);
					upperCase(unknownColors, 4);
				} while (unknownColors[4] != '\0' || checkForbiddenColors(unknownColors, 4));

				CLEAR()
				Title();
				printf("Joueur 2, proposez 4 couleurs de votre choix pour d%scouvrir la combinaison de Joueur 1:\n", CHARACTER1);
			}

			// VERIFICATION DES COULEURS PROPOSEES PAR LE JOUEUR

			int wellPlacedColors = 0, misplacedColors = 0, turns = 8;
			char playerColors[5] = {0};

			do
			{
				do
				{
					playerColors[4] = 1;
					scanf("%s", playerColors);
					upperCase(playerColors, 4);
				} while (playerColors[4] != '\0' || checkForbiddenColors(playerColors, 4));

				wellPlacedColors = 0;
				for (i = 0; i < 4; ++i)
				{
					if (unknownColors[i] == playerColors[i])
					{
						wellPlacedColors++;
					}
				}

				misplacedColors = 0;
				for (i = 0; i < 4; ++i)
				{
					if (checkColorTab(playerColors[i], unknownColors, 4) && unknownColors[i] != playerColors[i])
					{
						misplacedColors++;
					}
				}
				turns--;

				if (turns != 0 && wellPlacedColors != 4)
				{
					char plural1 = plural(wellPlacedColors), plural2 = plural(misplacedColors), plural3 = plural(turns);
					printf("Vous avez %d couleur%c bien plac%se%c. Vous avez %d couleur%c mal plac%se%c.\nIl vous reste %d coup%c.\n", wellPlacedColors, plural1, CHARACTER1, plural1, misplacedColors, plural2,CHARACTER1, plural2, turns, plural3);
				}
			} while (wellPlacedColors != 4 && turns != 0);

			if (screen == 1)
			{
				if (wellPlacedColors == 4)
				{
					printf("\nBravo!! Vous avez gagn%s!\n\n", CHARACTER1);
				}
				else
				{
					printf("\nD%ssol%s, vous avez perdu...\n\n", CHARACTER1, CHARACTER1);
					printf("La solution %stait: %s\n\n", CHARACTER1, unknownColors);
				}
			}

			if (screen == 2)
			{
				if (wellPlacedColors == 4)
				{
					printf("\nBravo Joueur2!! Vous avez gagn%s, vous avez trouv%s la combinaison de Joueur1!\n\n", CHARACTER1, CHARACTER1);
				}
				else
				{
					printf("\nD%ssol%s Joueur2... Vous avez perdu\n\n", CHARACTER1, CHARACTER1);
					printf("La combinaison de Joueur1 %stait: %s\nBravo Joueur1!\n\n", CHARACTER1, unknownColors);
				}
			}
			printf("Une autre partie?\n1. 1 joueur\n2. 2 joueurs\n0. Quitter\n\n");
		}

		if (screen == 3)
		{
			printf("D%scouvrez les quatres lettres myst%sres.\nLes lettres peuvent %stre les suivantes:\n     ABCDEFGH\nVous n'avez que 8 coups.\nFaites vos propositions sans espace entre les lettres, comme l'exemple suivant:\n     GECD\n\nA vous de jouez! Bonne chance!\n\n\n1. 1 joueur\n2. 2 joueurs\n", CHARACTER1, CHARACTER2, CHARACTER3);
		}

		scanf("%d", &screen);
		CLEAR()
	} while (screen);

	return 0;
}

//tirer aléatoirement une valeur
int randomColors(int MIN, int MAX)
{
	return rand() % (MAX -MIN + 1) + MIN;
}

//vérifier si la lettre est bien compris dans le tableau
int checkColorTab(int comparedColor, char *colors, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (colors[i] == comparedColor)
		return 1;
	}
	return 0;
}

// vérifier si la lettre proposée est bien compris entre A et H
int checkForbiddenColors(char *colors, int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		if (colors[i] < 65 || colors[i] > 72)
		return 1;
	}
	return 0;
}


// convertir les minuscules de a à h en majuscule de A à H
void upperCase(char *colors, int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		if (colors[i] >= 97 && colors[i] <= 104)
		{
			colors[i] -= 32;
		}
	}
}

// afficher le titre
void Title()
{
	printf("      ##########################\n");
	printf("      #                        #\n");
	printf("      #       MasterMind       #\n");
	printf("      #                        #\n");
	printf("      #              ABCDEFGH  #\n");
	printf("      ##########################\n\n\n");
}

char plural(int value)
{
	return (value > 1) ? 's' : 0;
}
