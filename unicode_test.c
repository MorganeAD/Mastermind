#include <wchar.h>
#include <locale.h>
#include <string.h>

void borderMaker(char *border, char *leftCorner, char *rightCorner, char *line, int difficulty);
void boardPrinter(int difficulty);
void upSquareMaker(char *border, char *doubleVertical, char *simpleUpRightCorner, char *simpleHorizontal, char *simpleUpLeftCorner, char *space);
 
int main()
{
    int difficulty = 4;

    boardPrinter(difficulty);

    return 0;
}


void borderMaker(char *border, char *leftCorner, char *rightCorner, char *line, int lineNumber)
{
    strcat(border, leftCorner);

    for (int i = 0; i < lineNumber; ++i)
    {
        strcat(border, line);
    }
    
    strcat(border, rightCorner);
}


void boardPrinter(int difficulty)
{
    setlocale(LC_ALL, "");
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

    char upSquareBorder[1000] = {0};
    char downSquareBorder[1000] = {0};
    char sideSquareBorder[1000] = {0};
    char emplyLine[1000] = {0};

    borderMaker(upBorder, doubleDownRightCorner, doubleDownLeftCorner, doubleHorizontal, (10*difficulty));
    upSquareMaker(upSquareBorder, doubleVertical, simpleDownRightCorner, simpleHorizontal, simpleDownLeftCorner, space);
    borderMaker(downBorder, doubleUpRightCorner, doubleUpLeftCorner, doubleHorizontal, (10*difficulty));

    wprintf(L"%s\n", upBorder);
    wprintf(L"%s\n", upSquareBorder);
    wprintf(L"%s\n", downBorder);

}

void upSquareMaker(char *border, char *doubleVertical, char *simpleDownRightCorner, char *simpleHorizontal, char *simpleDownLeftCorner, char *space)
{
    int i, j;
    strcat(border, doubleVertical);
    strcat(border, space);
    for (int i = 0; i < 4; ++i)
    {
        strcat(border, simpleDownRightCorner);
        for (j = 0; j < 3; ++j)
        {
            strcat(border, simpleHorizontal);
        }
        strcat(border, simpleDownLeftCorner);

        strcat(border, space);
    }

    strcat(border, doubleVertical);


}

//gcc -std=c99 unicode_test -o test
//https://en.wikipedia.org/wiki/Box-drawing_character#Unicode
