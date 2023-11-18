//
// Created by brais on 14/11/2023.
// Los prints etc sirven para ver como vamos, en un programa real no los pondríamos, al igual que algunas cosas de cálculos de comprobación
//
#include <stdio.h>
void calcularLongitud(char *cadena, int *longitud) // Queremos una cadena de caracteres y la dirección de memoria de la variable donde almacenaremos la longitud
{
    while(cadena[*longitud] != '\0')  // Las cadenas terminan en \0
    {
        *longitud += 1;  // Debemos actualizar el valor de la variable, por lo que debemos acceder al contenido
    }
}

void concatenarCadenas(char *cadena1, char *cadena2, char *resultado)
{
    int longitudC1 = 0; // Obtenemos la longitud de la primera cadena
    calcularLongitud(cadena1, &longitudC1);
    int indice = 0; // Establecemos el índice
    for(; indice < longitudC1; indice++)
    {
       resultado[indice] = cadena1[indice];  // Introducimos los caracteres de la primera cadena en la segunda
    }
    resultado[indice] = ' ';  // Añadimos el espacio
    indice++; // Actualizamos el índice actual
    int longitudC2 = 0; // Calculamos la longitud de la segunda cadena
    calcularLongitud(cadena2, &longitudC2);
    printf("c1 - %s // c2 - %s // res - %s\n", cadena1, cadena2, resultado);
    for(; indice < longitudC1 + longitudC2 +1; indice++)
    {
        resultado[indice] = cadena2[indice-longitudC1-1]; // Introducimos de forma concatenada los valores comenzando por la primera posición de la segunda cadena
        /*
         * hola -> 4
         * que tal
         * hola + 1 por el ' '
         * indice (5) - longitud1(4) - ' '(1)
         */
    }
    resultado[indice] = '\0'; // Añadir el \0
    printf("c1 - %s // c2 - %s // res - %s\n", cadena1, cadena2, resultado);
}

int main()
{
    // Leer la entrada
    char cadena1[50];
    printf("Introduzca la primera cadena:\n");
    gets(&cadena1);
    char cadena2[50];
    printf("Introduzca la segunda cadena:\n");
    gets(&cadena2);

    // Comprobar la entrada en cada punto
    printf("Las cadenas son:\n%s\n%s", cadena1, cadena2);

    // Calcular las longitudes de las cadenas
    int longitud1 = 0, longitud2 = 0;
    calcularLongitud(cadena1, &longitud1); // Queremos modificar el valor de longitud -> pasar la dirección de memoria de esta variable
    calcularLongitud(cadena2, &longitud2);
    printf("Las longitudes son: %d - %d\n", longitud1, longitud2); // Comprobar que las longitudes se han modificado de forma correcta

    char resultado[longitud1+longitud2+2]; // Dar el tamaño a la cadena en la que almacenaremos los resultados
    concatenarCadenas(cadena1, cadena2, resultado); // Concatenar las cadenas

    return 0;
}
