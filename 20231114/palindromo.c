//
// Created by brais on 14/11/2023.
// Hay algunas instrucciones como algún print que se pueden saltar, pero quedan ahí para ir comprobando paso a paso
//
#include <stdio.h>

void calcularLongitud(char *cadena, int *longitud) // Almacenaremos la longitud en la variable correspondiente
{
    while(cadena[*longitud] != '\0')
    {
        *longitud += 1; // Accedemos a la variable y sumamos uno por cada letra
    }
}

void esPalindromo(char *cadena)
{
    int longitud;
    calcularLongitud(cadena, &longitud); // Obtenemos la longitud de la cadena
    printf("%d\n", longitud);
    for (int i = 0; i < longitud; i++)
    {
        if (cadena[i] != cadena[longitud-i-1]) // Accedemos a las posiciones correspondientes: (primera y última // segunda y penúltima...)
        {
            printf("No es palíndromo");
            return; // Si son distintos sabemos que no es palíndromo y paramos la ejecución
        }
    }
    printf("Es palindromo"); // Si termina el bucle significa que todas las comprobaciones fueron exitosas, por lo que la palabra en sí es un palíndromo
}

int main()
{
    printf("Introduce una cadena:");
    char cadena[50];
    gets(&cadena);
    printf("la cadena es: %s\n", cadena);
    esPalindromo(cadena);
    return 0;
}