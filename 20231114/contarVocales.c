//
// Created by brais on 14/11/2023.
// Hay algunas instrucciones como algún print que se pueden saltar, pero quedan ahí para ir comprobando paso a paso
//
#include <stdio.h>

void contarVocales(char *cadena, int *nVocales) // Necesitamos la dirección de memoria para establecer su valor
{
    int i = 0;
    while(cadena[i] != '\0') // Las cadenas acaban en 0
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u') {
            *nVocales += 1; // Accedemos al contenido y cambiamos el valor si es una vocal en minúscula
        }
        i++;
    }

    printf("El número de vocales es %d\n", *nVocales);
}

int main()
{
    // Leer entrada
    printf("Introduzca una frase:\n");
    char cadena[50];
    gets(&cadena);

    // Establecer el número de vocales
    int numeroVocales = 0;
    contarVocales(cadena, &numeroVocales); // Debemos actualizar dicho número
    printf("El número de vocales es %d\n", numeroVocales);

}
