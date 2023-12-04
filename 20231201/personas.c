//
// Created by brais on 01/12/2023.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// Incluimos las librerías

struct persona // struct de personas
{
    char nombre[20];
    int edad;
    struct direccion // struct dentro de struct
    {
       int codigoPostal;
    } dir;
};

void introducirDatosManual(struct persona *p) // Introducir datos de forma manual
{
    p->edad = 25;
    p->dir.codigoPostal = 12345;
    strcpy(p->nombre, "Juan");
}

void imprimirPersona(struct persona p) // Imprimir personas
{
    printf("El nombre de la persona es: %s\n", p.nombre);
    printf("La edad de la persona es: %d\n", p.edad);
    printf("El codigo postal de la persona es: %d\n", p.dir.codigoPostal);
}

void introducirDatosAleatorio(struct persona *p) // Introducir datos aleatorios
{
    p->edad = (rand() % 10) + 20;
    p->dir.codigoPostal = (rand() % 89999) + 10000;
    char nombres[5][20] = {"Eusebio", "Maria", "Rogelio", "Pepe", "Pericles"};  // Definimos una lista de nombres como posibilidades para cada elemento
    strcpy(p->nombre, nombres[rand() % 5]); // Se genera un número aleatorio entre 0 y 4 correspondiente a cada posición
}

int main()
{
    srand(time(NULL));
    struct persona p;
    printf("Introduciendo valores de forma manual....\n");
    introducirDatosManual(&p);
    imprimirPersona(p);
    printf("\n\n");

    struct persona p2;
    printf("Introduciendo valores de forma aleatoria....\n");
    introducirDatosAleatorio(&p2);
    imprimirPersona(p2);

    int numeroPersonas = 1000;
    struct persona personas[numeroPersonas];
    for(int i = 0; i < numeroPersonas; i++)
    {
        introducirDatosAleatorio(&personas[i]);
    }

    /*for(int i = 0; i < numeroPersonas; i++)
    {
        imprimirPersona(personas[i]);
    }*/

    int edadABuscar = 25;
    printf("\nBuscando personas de forma secuencial....\n");

    int tiempoInicial = time(NULL);  // calcular el tiempo que se tarda en buscar
    for(int i = 0; i < numeroPersonas; i++)
    {
        if (personas[i].edad == edadABuscar)
        {
            imprimirPersona(personas[i]);
            break;
        }
    }
    int tiempoFinal = time(NULL); // Hora en la que acabo
    printf("La búsqueda secuencial ha tardado %d\n", tiempoFinal - tiempoInicial); // La diferencia entre el tiempo al inicio y el tiempo al final es lo que tardó el bucle

    printf("\n\n");

    printf("\nBuscando personas de forma secuencial inversa....\n");
    tiempoInicial = time(NULL);
    for(int i = numeroPersonas; i > 0; i--)
    {
        if (personas[i].edad == edadABuscar)
        {
            imprimirPersona(personas[i]);
            break;
        }
    }
    tiempoFinal = time(NULL);
    printf("La búsqueda secuencial inversa ha tardado %d\n", tiempoFinal - tiempoInicial);

    printf("\n\n");

    printf("\nBuscando personas de forma aleatoria....");
    int indiceBuscar = rand() % numeroPersonas;
    while (1)
    {
        if (personas[indiceBuscar].edad == edadABuscar)
        {
            imprimirPersona(personas[indiceBuscar]);
            break;
        }
        indiceBuscar = rand() % numeroPersonas;
    }

    return 0;
}