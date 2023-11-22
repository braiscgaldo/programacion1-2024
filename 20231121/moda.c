//
// Created by brais on 14/11/2023.
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

void contarDigito(int *arrayNum, int longitud, int digito, int *contador)
{
    for (int i = 0; i < longitud; i++) // Para cada posición del array
    {
        if (arrayNum[i] == digito) // Si es el dígito en cuestíon aumentar 1 en el contador
        {
            *contador+=1;
        }
    }
}

void calcularModa(int *arrayNum, int longitud, int* valorMaximoRepetido, int *numeroDeVecesMaximasRepetidas)
{
    int contador, digitoActual;
    for(int i = 0; i < longitud; i++) // Para cada posición del array
    {
        digitoActual = arrayNum[i]; // El dígito actual es el de la posición actual
        contador = 0; // Inicializamos el contador a 0
        contarDigito(arrayNum, longitud, digitoActual, &contador); // Realizamos la función de conteo y almacenamos el resultado en contador
        printf("posicionArray %d, digito: %d, veces repetido:%d\n", i, arrayNum[i], contador); // Damos feedbak
        if (contador >= *numeroDeVecesMaximasRepetidas) // Si el contador es mayor que el número de veces repetidas más alto
        {
            *valorMaximoRepetido = arrayNum[i]; // Actualizamos el valor máximo repetido
            *numeroDeVecesMaximasRepetidas = contador; // Actualizamos el número de veces máximo repetido
        }
    }

    printf("La moda es %d y el numero de veces que se repite %d\n", *valorMaximoRepetido, *numeroDeVecesMaximasRepetidas); // Notificamos el resultado dando feedback
}

int main()
{
    int longitud;

    printf("Introduzca la longitud del array:  ");
    scanf("%d", &longitud);
    int arrayNumeros[longitud]; // Declarar el array con la longitud deseada

    introducirNumerosAleatorio(arrayNumeros, longitud);
    //introducirNumeros(arrayNumeros, longitud);

    // Devolver la moda con el array
    int moda = arrayNumeros[0];
    int modaN = 1;
    calcularModa(arrayNumeros, longitud, &moda, &modaN); // Calculamos el valor de moda y el número de veces que se repite

    return 0;
}