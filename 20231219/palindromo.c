//
// Created by brais on 19/12/2023.
//
#include <stdio.h>

int longitudCadena(char * cadena)
{
    int longitud = 0;
    while (cadena[longitud] != '\0')
    {
        longitud++;
    }
    return longitud;
}
int esPalindromo(char *cadena, int longitud)
{
    for (int i = 0; i < longitud / 2; i++)
    {
        if (cadena[i] != cadena[longitud-i-1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char cadena[40];
    printf("Introduzca una cadena de caracteres: ");
    gets(&cadena);

    printf("\nLa cadena introducida es %s", cadena);

    printf("\nLa cadena es un palíndromo: %d", esPalindromo(cadena, longitudCadena(cadena)));
    return 0;
}