//
// Created by brais on 05/12/2023.
//
//
// Created by brais on 01/12/2023.
//
#include <stdio.h>

void introducirValoresSecuenciales(int * array, int longitud)
{
    for(int i = 0; i < longitud; i++)
    {
        array[i] = i;
    }
}

void imprimirArray(int * array, int longitud)
{
    printf("\nValores del array: ");
    for(int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int busquedaSecuencial(int *array, int longitud, int valorABuscar)
{
    for(int i = 0; i < longitud; i++)
    {
        if (array[i] == valorABuscar)
        {
            return i;
        }
    }
}

int busquedaSecuencialInversa(int *array, int longitud, int valorABuscar)
{
    for(int i = longitud; i > 0; i--)
    {
        if (array[i] == valorABuscar)
        {
            return longitud - i;
        }
    }
}
// Clase anterior
int busquedaBinaria(int *array, int izquierda, int derecha, int valorABuscar, int numeroIteraciones) // Función recursiva que recibe el array, la posición más a la izquierda donde buscar, la posición más a la derecha de donde buscar, el valor buscado y el número de iteraciones que lleva
{
    int pivote = (izquierda + derecha) / 2;  // Índice medio
    int valorPivote = array[pivote];  // Valor medio
    if (valorABuscar == valorPivote)
    {
        return numeroIteraciones; // Devolvemos el número de iteraciones si lo encontramos (a modo de ejercicio probad a devolver el índice)
    }
    else if (valorABuscar > valorPivote) // Si el valor es mayor
    {
        return busquedaBinaria(array, pivote + 1, derecha, valorABuscar, numeroIteraciones + 1); // El valor mínimo de la izquierda está en el pivote + 1
    }
    else
    {
        return busquedaBinaria(array, izquierda, pivote - 1, valorABuscar, numeroIteraciones + 1); // El valor máximo de la derecha está en el pivote - 1
    }
}

int main()
{
    int longitud = 1000;
    int array[longitud];

    printf("Introduciendo valores en array....");
    introducirValoresSecuenciales(array, longitud);
    imprimirArray(array, longitud);

    int valorABuscar = 400;
    printf("El número de iteraciones que tardó en encontrar el elemento con busqueda secuencial ha sido: %d\n",
           busquedaSecuencial(array, longitud, valorABuscar));

    printf("El número de iteraciones que tardó en encontrar el elemento con busqueda secuencial inversa ha sido: %d\n",
           busquedaSecuencialInversa(array, longitud, valorABuscar));

    printf("El número de iteraciones que tardó en encontrar el elemento con busqueda binaria ha sido: %d\n",
           busquedaBinaria(array, 0, longitud-1, valorABuscar, 0));

}
