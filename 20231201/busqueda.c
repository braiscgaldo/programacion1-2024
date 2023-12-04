//
// Created by brais on 01/12/2023.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void rellenarArray(int *array, int longitud) // Función de rellenar array ordenado
{
    for (int i = 0; i < longitud; i++)
    {
        array[i] = i;
    }
}

void imprimirArray(int *array, int longitud) // Imprimir array
{
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int busquedaSecuencial(int *array, int longitud, int valorABuscar) // Búsqueda secuencial
{
    for(int i = 0; i < longitud; i++)
    {
        if(array[i] == valorABuscar)
        {
            return i;
        }
    }
}

int busquedaSecuencialInversa(int *array, int longitud, int valorABuscar) // Búsqueda secuencial inversa
{
    for(int i = longitud; i > 0; i--)
    {
        if(array[i] == valorABuscar)
        {
            return longitud - i;
        }
    }
}

int busquedaAleatoria(int *array, int longitud, int valorABuscar)  // Búsqueda aleatoria
{
    int indiceBuscar = rand() % longitud;
    int iteracion = 0;
    while (1)
    {
        if (array[indiceBuscar] == valorABuscar)
        {
            break;
        }
        iteracion++;
        indiceBuscar = rand() % longitud;
    }
    return iteracion;
}

int main()
{
    srand(time(NULL));
    int longitud = 10000;
    int array[longitud];

    printf("Introduciendo datos en el array...\n");
    rellenarArray(array, longitud);
    imprimirArray(array, longitud);

    int valorBuscado = 2;
    printf("\nLa búsqueda secuencial ha llevado %d iteraciones\n", busquedaSecuencial(array, longitud, valorBuscado));
    printf("\nLa búsqueda secuencial inversa ha llevado %d iteraciones\n", busquedaSecuencialInversa(array, longitud, valorBuscado));
    printf("\nLa búsqueda aleatoria ha llevado %d iteraciones\n", busquedaAleatoria(array, longitud, valorBuscado));


    return 0;
}
