//
// Created by brais on 05/12/2023.
//
#include <stdio.h>
#include <time.h> // Librerias para la aleatorización
#include <stdlib.h>

void generarArrayAleatorio(int *array, int longitud)
{
    for(int i = 0; i < longitud; i++)
    {
        array[i] = rand() % longitud; // Generar un array que cumpla que el número más alto no puede superar la longitud y sea mayor que 0
    }
}

void imprimirArray(int *array, int longitud)
{
    for(int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    }
}

void intercambiarElementos(int *array, int izquierda, int derecha)
{
    int temporal = array[izquierda];  // Variable temporal para la asignación
    array[izquierda] = array[derecha];
    array[derecha] = temporal;
}

int ordenacionBurbuja(int array[], int longitud)
{
    int ordenado = 0;
    int contador = 0;
    while (!ordenado) // Mientras no esté ordenado
    {
        ordenado = 1;  // Ordenado se pone a verdadero
        for(int i=0; i < longitud - 1; i++)
        {
            contador++;
            if (array[i] > array[i+1]) // Intercambia elementos entre sí si un valor es mayor que el siguiente
            {
                intercambiarElementos(array, i, i+1);
                ordenado = 0; // Si se realiza un intercambio, el array ya no está ordenado
            }
        }
    }

    return contador; // Devolvemos el número de iteraciones -> El array ordenado se encuentra en la variable correspondiente
}

int valorIndiciceIntercambio(int *array, int inicio, int longitud)
{
    int valorMin = array[inicio];
    int indiceMin = inicio; // Se selecciona el primer valor del array
    for (int i = inicio + 1; i < longitud; ++i) { // Se coge el array restante para coger su valor
        if (valorMin > array[i])
        {
            valorMin = array[i];
            indiceMin = i;
        }
    }

    return indiceMin;
}

int ordenacionInsercion(int *array, int longitud)
{
    int indiceIntercambio;
    for(int i = 0; i < longitud; i++)
    {
        indiceIntercambio = valorIndiciceIntercambio(array, i, longitud); // Se intercambia la posición actual por el menor número en el array restante
        intercambiarElementos(array, i, indiceIntercambio);
    }

    return longitud;
}



int main()
{
    int longitud = 10;
    int array[longitud];
    srand(time(NULL));

    generarArrayAleatorio(array, longitud);
    imprimirArray(array, longitud);

    printf("\n\n");
    intercambiarElementos(array, 0, 1);
    imprimirArray(array, longitud);
    printf("\nLa ordenación por burbuja ha llevado %d iteraciones\n", ordenacionBurbuja(array, longitud));
    imprimirArray(array, longitud);


    generarArrayAleatorio(array, longitud); // Se vuelve a generar otro array porque el anterior ya está ordenado y almacenado en la variable correspondiente

    printf("El índice en el que se encuentra el valor minimo es %d\n", valorIndiciceIntercambio(array, 5, longitud));
    printf("\nLa ordenación por burbuja ha llevado %d iteraciones\n", ordenacionBurbuja(array, longitud));
    imprimirArray(array, longitud);


    return 0;
}

