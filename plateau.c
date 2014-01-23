#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define CLEAR() system("clear");


int main(int argc, char const *argv[])
{
	CLEAR()
	char unknownColors[10] = {0};
	unknownColors[0] = 65;
	unknownColors[1] = 66;
	unknownColors[2] = 67;
	unknownColors[3] = 68;

	char borderTop[39] = {0};
	for (int i = 0; i < 38; ++i)
	{
		borderTop[i] = 205;
	}

	printf("  %s\n", borderTop);
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  | %c |  | %c |  | %c |  | %c |  _ _  #\n", unknownColors[0], unknownColors[1], unknownColors[2], unknownColors[3]);
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #   ___    ___    ___    ___        #\n");
	printf("  #  |   |  |   |  |   |  |   |  _ _  #\n");
	printf("  #  |___|  |___|  |___|  |___|  _ _  #\n");
	printf("  #                                   #\n");
	printf("  #lettres autorisées: A B C D E F G H#\n");
	printf("  #####################################\n\n");

	return 0;
}
