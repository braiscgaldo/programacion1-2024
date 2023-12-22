//
// Created by brais on 19/12/2023.
//
#include <stdio.h>

int estaEnCadena(char *cadena, char caracter)
{
    int indice = 0;
    while (cadena[indice] != '\0')
    {
        if (cadena[indice] == caracter)
        {
            return 1;
        }
        indice++;
    }
    return 0;
}

void caracteresDuplicados(char *cadena)
{
    int indiceCadena=0;
    int indiceDuplicados = 0;
    char duplicados[50];
    while (cadena[indiceCadena] != '\0')
    {
        if (!(estaEnCadena(duplicados, cadena[indiceCadena])))
        {
            duplicados[indiceDuplicados] = cadena[indiceCadena];
            duplicados[indiceDuplicados+1] = '\0';
            indiceDuplicados++;
        }
        indiceCadena++;
    }

    printf("\nLa cadena sin caracteres duplicados es: %s", duplicados);
}

int main()
{
    char * cadena[50];
    char * duplicados[50];
    printf("Introduzca una cadena:");
    gets(cadena);

    printf("\nLa cadena introducida es: %s", cadena);

    printf("\nEl caracter 'h' está en la cadena %s: %d", cadena, estaEnCadena(cadena, 'h'));
    caracteresDuplicados(cadena);
    return 0;
}
