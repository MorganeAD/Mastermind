#include <wchar.h>
#include <locale.h>
#include <string.h>

void borderMaker(char *border, char *leftCorner, char *rightCorner, char *line, int difficulty);
void boardPrinter(int difficulty);
void upDownBorderSquareMaker(char *border, char *doubleVertical, char *simpleLeftCorner, char *simpleHorizontal, char *simpleRightCorner, char *space);
void sideSquareMaker(char *border,char *doubleVertical,char *simpleVertical,char *space, char *underscore);

 
int main()
{
    int difficulty = 4;

    boardPrinter(difficulty);

    return 0;
}




void boardPrinter(int difficulty)
{
    int i;
    setlocale(LC_ALL, "");

    char underscore[] = "_";

    char doubleHorizontal[] = "\u2550";
    char doubleVertical[] = "\u2551";
    char doubleDownRightCorner[] = "\u2554";
    char doubleDownLeftCorner[] = "\u2557";
    char doubleUpRightCorner[] = "\u255A";
    char doubleUpLeftCorner[] = "\u255D";

    char simpleHorizontal[] = "\u2500";
    char simpleVertical[] = "\u2502";
    char simpleDownRightCorner[] = "\u250C";
    char simpleDownLeftCorner[] = "\u2510";
    char simpleUpRightCorner[] = "\u2514";
    char simpleUpLeftCorner[] = "\u2518";

    char space[] = "\u00A0";

    char upBorder[1000] = {0};
    char downBorder[1000] = {0};

    char upSquareBorder[8][1000] = {0};
    char downSquareBorder[8][1000] = {0};
    char sideSquareBorder[8][1000] = {0};
    char emplyLine[1000] = {0};

    borderMaker(upBorder, doubleDownRightCorner, doubleDownLeftCorner, doubleHorizontal, (8*difficulty+2));
    for (i = 0; i < 8; ++i)
    {
        upDownBorderSquareMaker(upSquareBorder[i], doubleVertical, simpleDownRightCorner, simpleHorizontal, simpleDownLeftCorner, space);
        sideSquareMaker(sideSquareBorder[i], doubleVertical, simpleVertical, space, underscore);
        upDownBorderSquareMaker(downSquareBorder[i], doubleVertical, simpleUpRightCorner, simpleHorizontal, simpleUpLeftCorner, space);
    }
    borderMaker(downBorder, doubleUpRightCorner, doubleUpLeftCorner, doubleHorizontal, (8*difficulty+2));


    wprintf(L"%s\n", upBorder);
    for (i = 0; i < 8; ++i)
    {
        wprintf(L"%s\n", upSquareBorder[i]);
        wprintf(L"%s\n", sideSquareBorder[i]);
        wprintf(L"%s\n", downSquareBorder[i]);
    }
    wprintf(L"%s\n", downBorder);
}

void borderMaker(char *border, char *leftCorner, char *rightCorner, char *line, int lineNumber)
{
    int i;
    strcat(border, leftCorner);
    for (i = 0; i < lineNumber; ++i)
    {
        strcat(border, line);
    }
    strcat(border, rightCorner);
}


void upDownBorderSquareMaker(char *border, char *doubleVertical, char *simpleLeftCorner, char *simpleHorizontal, char *simpleRightCorner, char *space)
{
    int i, j;
    strcat(border, doubleVertical);
    strcat(border, space);
    for (int i = 0; i < 4; ++i)
    {
        borderMaker(border, simpleLeftCorner, simpleRightCorner, simpleHorizontal, 3);
        strcat(border, space);
    }

    for (int i = 0; i < 9; ++i)
    {
        strcat(border, space);
    }
    strcat(border, doubleVertical);
}


void sideSquareMaker(char *border,char *doubleVertical,char *simpleVertical,char *space, char *underscore)
{
    int i, j;
    strcat(border, doubleVertical);
    strcat(border, space);
    for (i = 0; i < 4; ++i)
    {
        strcat(border, simpleVertical);
        for (j = 0; j < 3; ++j)
            {
                strcat(border, space);
            }
        strcat(border, simpleVertical);
        strcat(border, space);
    }
    for (int i = 0; i < 4; ++i)
    {
        strcat(border, space);
        strcat(border, underscore);

    }
    strcat(border, space);
    strcat(border, doubleVertical);
}



//gcc -std=c99 unicode_test -o test
//https://en.wikipedia.org/wiki/Box-drawing_character#Unicode