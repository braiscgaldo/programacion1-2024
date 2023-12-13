//
// Created by brais on 12/12/2023.
//

#include <stdio.h>

void contarVocales(char * cadena)
{
    int indice = 0;
    int contador = 0;
    while(cadena[indice] != '\0' && cadena[indice] != '*')
    {
        if (cadena[indice] == 'a' || cadena[indice] == 'e' || cadena[indice] == 'i' || cadena[indice] == 'o' || cadena[indice] == 'u' || cadena[indice] == 'A' || cadena[indice] == 'E' || cadena[indice] == 'I' || cadena[indice] == 'O' || cadena[indice] == 'U')
        {
            contador++;
        }
        indice++;
    }

    printf("\nHay %d vocales hasta final de cadena o *", contador);

    for(int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            contador++;
        }
    }
    printf("\nHay %d vocales hasta final de cadena o * con for", contador);
}


int main()
{
    printf("Introduzca una cadena de caracteres:\n");
    char cadena[50];
    gets(cadena);

    printf("La cadena es: %s", cadena);

    contarVocales(cadena);

    return 0;
}
