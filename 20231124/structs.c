//
// Created by brais on 24/11/2023.
//
#include <stdio.h>
#include <string.h>

struct estudiante
{
    char nombre[20]; // Definimos los campos con sus respectivos tipos
    int edad;
    float nota;
    float altura;
    float peso;
    float imc;
};

void imprimirEstudiante(struct estudiante e)
{  // Imprimimos los campos de cada struct estudiante

    printf("El nombre del estudiante es %s\n", e.nombre);
    printf("La edad del estudiante es %d\n", e.edad);
    printf("La nota del estudiante es %f\n", e.nota);
    printf("La altura del estudiante es %f\n", e.altura);
    printf("El peso del estudiante es %f\n", e.peso);
    printf("El IMC del estudiante es %f\n", e.imc);
    printf("\n");
}

float calcularIMC(struct estudiante e)
{
    return e.peso / ((e.altura / 100) * (e.altura / 100));  // Como el peso hemos decidido introducirlo en cm, es necesario dividirlo entre 100
}

void resetearIMC(struct estudiante *e)
{
    e->imc = 0;  // Reseteamos el imc a través de su dirección
}

struct estudiante crearEstudianteViejo(struct estudiante e)
{ // Creamos un estudiante a partir de otro copiando los campos uno a uno
    struct estudiante estudianteViejo;
    estudianteViejo.altura = e.altura;
    estudianteViejo.peso = e.peso;
    estudianteViejo.imc = e.imc;
    estudianteViejo.nota = e.nota;
    strcpy(estudianteViejo.nombre, e.nombre);
    estudianteViejo.edad = e.edad + 10;
    return estudianteViejo;
}

struct estudiante crearEstudianteViejoOtraForma(struct estudiante e)
{ // Creamos un estudiante a partir de otro de forma directa
    struct estudiante estudianteViejo = e;
    estudianteViejo.edad = e.edad + 10;
    return estudianteViejo;
}

int main()
{
    printf("Generar struct estudiante...\n");
    struct estudiante e;
    imprimirEstudiante(e);

    printf("Cambiando edad del estudiante...\n");
    e.edad = 20;
    imprimirEstudiante(e);

    printf("Cambiando nota del estudiante...\n");
    e.nota = 8.8f;
    imprimirEstudiante(e);

    printf("Cambiando nombre del estudiante...\n");
    strcpy(e.nombre, "Juan");
    imprimirEstudiante(e);

    printf("Cumplir años....\n");
    e.edad++;
    imprimirEstudiante(e);

    printf("Añadimos peso y altura...\n");
    e.peso = 75.0f;
    e.altura = 175.0f;
    imprimirEstudiante(e);

    printf("Calculando IMC....\n");
    e.imc = calcularIMC(e);
    imprimirEstudiante(e);

    printf("Reseteando IMC....\n");
    resetearIMC(&e);
    imprimirEstudiante(e);

    printf("Envejeciendo a Juan...\n");
    struct estudiante viejo = crearEstudianteViejo(e);
    printf("Juan joven:\n");
    imprimirEstudiante(e);
    printf("Juan viejo:\n");
    imprimirEstudiante(viejo);

    printf("Envejeciendo a Juan...\n");
    viejo = crearEstudianteViejoOtraForma(e);
    e.nota = 5.6; // Modificamos la nota del joven e imprimimos los resultados
    printf("Juan joven:\n");
    imprimirEstudiante(e);
    printf("Juan viejo:\n");
    imprimirEstudiante(viejo);

    if (e.nota > viejo.nota)
    {
        printf("El juan joven sacó más\n");
    } else if (e.nota == viejo.nota)
    {
        printf("Ambos sacaron la misma nota\n");
    } else
    {
        printf("El juan viejo sacó más\n");
    }

    return 0;
}
