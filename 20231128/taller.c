//
// Created by brais on 28/11/2023.
//
#include <stdio.h>
#include <stdlib.h> // Incluir por si hay algún fallo del compilador
#include <string.h>

struct pieza {  // Definimos el struct pìeza
    char nombre[20];  // Un nombre
    int precio;  // Un precio
    char tienda[20];  // Una ubicación
};

void introducirDatosManual(struct pieza *p)  // Función para introducir datos, teder en cuenta que lo que se recibe es un puntero
{
    printf("Introduce un nombre para la pieza:\n");
    gets(&p->nombre);  // Almacenamos el nombre con la función gets
    printf("\nIntroduce la tienda de la pieza:\n");
    gets(&p->tienda);  // Almacenamos la tienda con la función gets
    printf("\nIntroduce un precio para la pieza:\n");

    char prec[20];  // Este trozo de código comentado es por si no os funciona el scanf por el compilador
    gets(prec); // Leemos la variable precio
    p->precio = atoi(prec);  // La funcion atoi transforma una cadena de caracteres a un número, si no son dígitos fallará

    //scanf("%d", &p->precio);
}

void imprimirPieza(struct pieza p)  // Función para imprimir piezas
{
    printf("El nombre de la pieza es: %s\n", p.nombre);
    printf("El precio de la pieza es: %d\n", p.precio);
    printf("La tienda en la que se encuentra la pieza es: %s\n", p.tienda);
}

void imprimirPiezasCoruna(struct pieza *piezas, int longitud) // Función imprimir piezas de coruña
{
    for(int i = 0; i < longitud; i++)
    {
        if (!(strcmp(piezas[i].tienda, "C")))  // Strcmp sirve para comparar cadenas de caracteres, tened en cuenta que en este caso, "C" es una cadena de caracteres de 1 elemento -> ['C'] -- si la comparación es exitosa, la función devuelve 0
        {
            printf("Pieza encontrada! (%d)", i);
            imprimirPieza(piezas[i]);
        }
    }
}

int precioTotalFerrol(struct pieza *piezas, int longitud) // Funcion para calcular el precio total de Ferrol
{
    int precioTotal = 0;  // Acumulador para sumar el precio de cada pieza
    for(int i = 0; i < longitud; i++)
    {
        if (!(strcmp(piezas[i].tienda, "F")))
        {
            printf("\nPieza encontrada! (%d)", i);
            precioTotal += piezas[i].precio;
        }
    }
    return precioTotal;
}

int piezaMasCaraFerrol(struct pieza *piezas, int longitud) // Función obtener pieza más cara de Ferrol
{
    int precioMax = 0; // Precio máximo de las tiendas, se podría optimizar igualando al primer elemento del array: precioMax=piezas[0].precio
    for(int i = 0; i < longitud; i++)
    {
        if (!(strcmp(piezas[i].tienda, "F")))
        {
            if (precioMax < piezas[i].precio) {
                printf("\nPieza encontrada! (%d)", i);
                precioMax = piezas[i].precio;
            }
        }
    }
    return precioMax;
}

char ciudadConPiezaCara(struct pieza *piezas, int longitud)
{
    int precioMax = 0; // Reseteamos el precio máximo, se podría optimizar igualando al primer elemento del array: precioMax=piezas[0].precio
    char ciudad; // Ciudad con la pieza más cara, se podría optimizar igualando al primer elemento del array: precioMax=piezas[0].tienda[0]
    for(int i = 0; i < longitud; i++)
    {
        if (precioMax < piezas[i].precio)
        {
            ciudad = piezas[i].tienda[0]; // Se actualiza la tienda
            precioMax = piezas[i].precio; // Se actualiza el precio para tener en cuenta las siguientes iteraciones
        }
    }
    return ciudad;
}

int main()
{
    struct pieza pieza1;
    printf("Imprimimos la información original de la pieza:\n");
    imprimirPieza(pieza1);
    introducirDatosManual(&pieza1);
    imprimirPieza(pieza1);

    struct pieza piezas [3]; // Definimos un array de 3 piezas por sencillez
    for(int i = 0; i < 3; i++)
    {
        introducirDatosManual(&piezas[i]);  // Editamos cada una de las piezas
    }

    printf("\n\n");

    for(int i = 0; i < 3; i++)
    {
        printf("Imprimiendo pieza %d:\n",i);
        imprimirPieza(piezas[i]);  // Imprimimos cada una de las piezas
    }

    printf("\n\n");
    printf("\nBuscando piezas de Coruña (C)....\n");
    imprimirPiezasCoruna(piezas, 3);

    printf("\n\n");
    printf("\nCalculando el dinero total en la tienda de Ferrol (F)....\n");
    int precioTotal = precioTotalFerrol(piezas, 3);

    printf("\nEl precio total en piezas de la tienda de Ferrol es: %d cents.\n", precioTotal);

    printf("\n\n");
    printf("\nObteniendo la pieza más cara de la tienda de Ferrol (F)....\n");

    int precioMax = piezaMasCaraFerrol(piezas, 3);

    printf("\nLa pieza más cara de la tienda de Ferrol es: %d cents.\n", precioMax);

    printf("\n\n");
    printf("\nObteniendo la ciudad con la pieza más cara....\n");
    char ciudad = ciudadConPiezaCara(piezas, 3);

    printf("\nLa ciudad con la pieza más cara es: %c\n", ciudad);

    return 0;
}
