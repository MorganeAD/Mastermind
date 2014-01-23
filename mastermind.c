#define LINUX

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
	//char screen = 4;
	int screen = 4;
	int difficulty = 4;

	do
		{
		Title();

		if (screen == 4)
		{
			printf("1. 1 Joueur\n2. 2 Joueurs\n3. R%sgles\n", CHARACTER1);
		}
		else if (screen == 1 || screen == 2)
		{
			// INITIALISATION DU JEU, UN JOUEUR OU DEUX JOUEURS
			char unknownColors[10] = {0};
			switch (screen)
			{
				case 1:
					onePlayerGameInitialization(difficulty, unknownColors);
				break;
				case 2:
					twoPlayerGameInitialization(difficulty, unknownColors);
				break;
			}

			// VERIFICATION DES COULEURS PROPOSEES PAR LE JOUEUR
			char playerColors[10] = {0};
			int wellPlacedColors = 0, misplacedColors = 0, turns = 8;
			
			do
			{
				char unknownColorsCopy[10] = {0};
				strcpy(unknownColorsCopy, unknownColors);

				playerScanf(difficulty, playerColors);

				wellPlacedColorsVerification(difficulty, &wellPlacedColors, unknownColorsCopy, playerColors);
				misplacedColorsVerification(difficulty, &misplacedColors, unknownColorsCopy, playerColors);
				//printf("%s   %s\n", unknownColorsCopy, unknownColors);
				turns--;

				if (turns != 0 && wellPlacedColors != difficulty)
				{
					turnIndication(wellPlacedColors, misplacedColors, turns);
				}
			} while (wellPlacedColors != difficulty && turns != 0);

			// MESSAGE DE FIN DE PARTIE
			switch (screen)
			{
				case 1:
					onePlayerEndMessage(wellPlacedColors, difficulty, unknownColors);
				break;
				case 2:
					twoPlayerEndMessage(wellPlacedColors, difficulty, unknownColors);
				break;
			}
			printf("Une autre partie?\n1. 1 joueur\n2. 2 joueurs\n0. Quitter\n\n");
		}

		if (screen == 3)
		{
			printf("D%scouvrez les %d lettres myst%sres.\nLes lettres peuvent %stre les suivantes:\n     ABCDEFGH\nVous n'avez que 8 coups.\nFaites vos propositions sans espace entre les lettres, comme l'exemple suivant:\n     GECD\n\nA vous de jouez! Bonne chance!\n\n\n1. 1 joueur\n2. 2 joueurs\n", CHARACTER1, difficulty, CHARACTER2, CHARACTER3);
		}

		/*do
		{
			screen = 0;
			scanf("%s", &screen);
			printf("%d\n", screen);
		} while (screen != 1 && screen != 2 && screen != 3 && screen != 4 );*/

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

//Si CheckOnce est faux: vérifier si la lettre est bien compris dans le tableau, si checkOne est vrai: vérifier si la lettre est bien compris dans le tableau qu'une fois
int checkColorTab(int comparedColor, char *colors, int size, int checkOnce)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		//printf("%s\n", colors);
		if (colors[i] == comparedColor)
		{
			if (checkOnce)
			{
				colors[i] = 90;
			}
			return 1;
		}
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

// afficher un plurial si la valeur est supérieur à 1
char plural(int value)
{
	return (value > 1) ? 's' : 0;
}

// Tire aléatoire une combinaison de lettres
void onePlayerGameInitialization(int difficulty, char *unknownColors)
{
	srand(time(NULL));
	int drawnColor = 0;
	int i;

	for (i = 0; i < difficulty; ++i)
	{
		do
		{
			drawnColor = randomColors(65, 72);
		} while (checkColorTab(drawnColor, unknownColors, difficulty, 0));
		unknownColors[i] = drawnColor;
	}
	printf("Proposez %d couleurs de votre choix pour d%scouvrir la combinaison myst%sre:\n", difficulty, CHARACTER1, CHARACTER2);
}

// Demande au joueur 1 d'écrire une combinaison de lettres
void twoPlayerGameInitialization(int difficulty, char *unknownColors)
{
	printf("Joueur 1, proposez %d couleurs myst%sres à faire chercher %s Joueur 2:\n", difficulty, CHARACTER2, CHARACTER4);
	playerScanf(difficulty, unknownColors);
	CLEAR()
	Title();
	printf("Joueur 2, proposez %d couleurs de votre choix pour d%scouvrir la combinaison de Joueur 1:\n", difficulty, CHARACTER1);
}

// Demande au joueur une combinaison et vérifie qu'elle soit autorisée
void playerScanf(int difficulty, char *colors)
{
	do
	{
		colors[difficulty] = 90;
		scanf("%s", colors);
		upperCase(colors, difficulty);
		if (colors[difficulty] != '\0' || checkForbiddenColors(colors, difficulty))
		{
			printf("Je n'ai pas compris, proposez une autre combinaison:\n");
		}
	} while (colors[difficulty] != '\0' || checkForbiddenColors(colors, difficulty));
}

// Vérifie si les lettres proposées par le joueur sont bien placées
void wellPlacedColorsVerification(int difficulty, int *wellPlacedColors, char *unknownColorsCopy, char *playerColors)
{
	int i;
	*wellPlacedColors = 0;
	for (i = 0; i < difficulty; ++i)
	{
		if (unknownColorsCopy[i] == playerColors[i])
		{
			*wellPlacedColors +=  1;
			unknownColorsCopy[i] = 90;
		}
	}
}

// Vérifie si les lettres proposées par le joueur sont présentes et mal placées
void misplacedColorsVerification(int difficulty, int *misplacedColors, char *unknownColorsCopy, char *playerColors)
{
	int i;
	*misplacedColors = 0;
	for (i = 0; i < difficulty; ++i)
	{
		if (checkColorTab(playerColors[i], unknownColorsCopy, difficulty, 1) && unknownColorsCopy[i] != playerColors[i])
		{
			*misplacedColors += 1;
		}					
	}
}

// Phrase indicatrice écrite à chaque tour pour aider le joueur a trouvé la combinaison
void turnIndication(int wellPlacedColors, int misplacedColors, int turns)
{
	char plural1 = plural(wellPlacedColors), plural2 = plural(misplacedColors), plural3 = plural(turns);
	printf("Vous avez %d couleur%c bien plac%se%c. Vous avez %d couleur%c mal plac%se%c.\nIl vous reste %d coup%c.\n", wellPlacedColors, plural1, CHARACTER1, plural1, misplacedColors, plural2,CHARACTER1, plural2, turns, plural3);
}

// Message de fin de partie en mode 1 joueur
void onePlayerEndMessage(int wellPlacedColors, int difficulty, char *unknownColors)
{
	if (wellPlacedColors == difficulty)
	{
		printf("\nBravo!! Vous avez gagn%s!\n\n", CHARACTER1);
	}
	else
	{
		printf("\nD%ssol%s, vous avez perdu...\n\n", CHARACTER1, CHARACTER1);
		printf("La solution %stait: %s\n\n", CHARACTER1, unknownColors);
	}
}

// Message de fin de partie en mode 2 joueur
void twoPlayerEndMessage(int wellPlacedColors, int difficulty, char *unknownColors)
{
	if (wellPlacedColors == difficulty)
	{
		printf("\nBravo Joueur2!! Vous avez gagn%s, vous avez trouv%s la combinaison de Joueur1!\n\n", CHARACTER1, CHARACTER1);
	}
	else
	{
		printf("\nD%ssol%s Joueur2... Vous avez perdu\n\n", CHARACTER1, CHARACTER1);
		printf("La combinaison de Joueur1 %stait: %s\nBravo Joueur1!\n\n", CHARACTER1, unknownColors);
	}
}