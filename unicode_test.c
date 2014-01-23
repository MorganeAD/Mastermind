#include <wchar.h>
#include <locale.h>
#include <string.h>
 
int main()
{
    setlocale(LC_ALL, "");

    char code1[] = "\u2550";
    char code2[] = "\u2554";
    char code3[] = "\u2557";
    char codes[1000] = {0};

    strcat(codes, code2);

    for (int i = 0; i < 38; ++i)
    {
        strcat(codes, code1);
    }
    
    strcat(codes, code3);



    wprintf(L"%s\n", codes);
    return 0;
}

//gcc -std=c99 unicode_test -o test
//https://en.wikipedia.org/wiki/Box-drawing_character#Unicode
