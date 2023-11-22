//
// Created by brais on 21/11/2023.
//
#include <stdio.h>
#include <time.h>  // Librería para importar funciones relacionadas con el reloj del sistema
#include <stdlib.h> // Librería estándar de C

void introducirNumerosAleatorio(int *arrayNumeros, int longitud)
{
    srand(time(NULL)); // Inicializar la semilla para los números aleatorios
    int numeroIntroducir;
    for(int i = 0; i < longitud; i++) // Para cada posición del array
    {
        numeroIntroducir = rand() % 5 + 5; // Calcular un número entre 0 y 4 y sumarle 5 -> número entre 5 y 10
        printf("\nIntroduciendo el número %d en la posición %d", numeroIntroducir, i); // Feedback
        arrayNumeros[i] = numeroIntroducir; // Modificar el valor de la posición del array
    }
}

void introducirNumeros(int *arrayNumeros, int longitud)
{
    for(int i = 0; i < longitud; i++)  // Para cada posición del array
    {
        printf("\nIntroduzca el número %d:", i);
        scanf("%d", &arrayNumeros[i]); // Introducir un número
    }
}

void calcularMedia(int *arrayNumeros, int longitud, float *media)
{
    float acumulador = 0.0f;  // Acumulador para calcular el total
    for(int i = 0; i < longitud; i++) // Para cada posición del array
    {
        acumulador += arrayNumeros[i]; // Añadimos su valor al sumador
    }
    *media = acumulador / longitud; // Media tendrá el valor objetivo
}

float calcularMediaDevolverFlotante(int *arrayNumeros, int longitud) // Igual que el anterior pero sin necesidad de especificar media para que lo devuelva en dicha variable
{
    int acumulador = 0;
    for(int i = 0; i < longitud; i++)
    {
        acumulador += arrayNumeros[i];
    }

    return acumulador / longitud;
}

int main()
{
    int longitud;
    printf("Cuál es la longitud del array?");
    scanf("%d", &longitud); // Escanear la longitud del array

    int arrayNumeros[longitud];
    introducirNumerosAleatorio(arrayNumeros, longitud); // Introducir números

    float media;
    calcularMedia(arrayNumeros, longitud, &media); // Calcular la media

    // float media = calcularMediaDevolverFlotante(arrayNumeros, longitud);  // Para utilizar esta forma se deben comentar las 2 líneas superiores
    printf("\nLa media es %f", media); // Imprimir resultado


    return 0;
}
