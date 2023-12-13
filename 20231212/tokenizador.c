//
// Created by brais on 12/12/2023.
//
#include <stdio.h>

void tokenizar(char *cadena)
{
    int i = 0;
    int contadorLetras = 0;
    while(cadena[i] != '\0')
    {
        while (cadena[i] != ',' && cadena[i] != '.' && cadena[i] != '\0')
        {
            printf("%c", cadena[i]);
            contadorLetras++;
            i++;
        }
        printf("        %d\n", contadorLetras);
        contadorLetras = 0;
        i++;
    }
}

void contarCaracteres(char *cadena, char caracter)
{
    int contador = 0;
    int indice = 0;

    while(cadena[indice] != '\0') {
        if (cadena[indice] == caracter)
        {
            contador++;
        }
        indice++;
    }

    printf("\nEl caracter %c aparece %d veces\n",  caracter, contador);
}

void contarTodosCaracteres(char * cadena)
{
    int indice = 0;

    while(cadena[indice] != '\0') {
        contarCaracteres(cadena, cadena[indice]);
        indice++;
    }
}

int main()
{
    int caracterMax;
    printf("Cuantos caracteres tendra de maximo tu cadena?");
    scanf(" %d", &caracterMax);

    printf("Definiendo cadena de %d caracteres: \n", caracterMax);
    char cadena[caracterMax];
    scanf("%s", &cadena);
    printf("La cadena introducida es: %s\n", cadena);

    tokenizar(cadena);

    contarCaracteres(cadena, 'e');

    contarTodosCaracteres(cadena);

    return 0;
}
