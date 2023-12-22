//
// Created by brais on 15/12/2023.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct personaje
{
    char nombre[20];
    int vida;
    int ataque;
    int armadura;
};


void introducirDatosGoku(struct personaje *g)
{
    strcpy(g->nombre, "Goku");
    printf("\nIntroduzca la vida del personaje %s:", g->nombre);
    scanf("%d", &g->vida);
    printf("\nIntroduzca el ataque del personaje %s:", g->nombre);
    scanf("%d", &g->ataque);
    printf("\nIntroduzca la armadura del personaje %s:", g->nombre);
    scanf("%d", &g->armadura);
}

void introducirDatosFreezer(struct personaje *f)
{
    strcpy(f->nombre, "Freezer");
    printf("\nIntroduzca la vida del personaje %s:", f->nombre);
    scanf("%d", &f->vida);
    printf("\nIntroduzca el ataque del personaje %s:", f->nombre);
    scanf("%d", &f->ataque);
    printf("\nIntroduzca la armadura del personaje %s:", f->nombre);
    scanf("%d", &f->armadura);
}

void imprimirPersonaje(struct personaje p)
{
    printf("\nEl nombre del personaje es: %s", p.nombre);
    printf("\nLa vida del personaje es: %d", p.vida);
    printf("\nEl ataque del personaje es: %d", p.ataque);

}

void atacar(struct personaje atacante, struct personaje *atacado)
{
    int puntosAtaque = rand() % atacante.ataque;
    if(atacado->armadura - puntosAtaque > 0)
    {
        puntosAtaque = 0;
    }else
    {
        puntosAtaque -= atacado->armadura;
    }
    atacado->vida -= puntosAtaque;

    printf("\n%s ha atacado a %s con una fuerza de %d y ahora %s tiene %d puntos de vida",
           atacante.nombre, atacado->nombre, puntosAtaque, atacado->nombre, atacado->vida);
    if (atacado->vida <= 0)
    {
        printf("\n%s ha muerto!!!!\n", atacado->nombre);
    }

}

int main()
{
    srand(time(NULL));
    struct personaje goku;
    struct personaje freezer;

    introducirDatosGoku(&goku);
    introducirDatosFreezer(&freezer);

    imprimirPersonaje(goku);
    imprimirPersonaje(freezer);

    while (goku.vida > 0)
    {
        if(!(rand() % 2))
        {
            atacar(goku, &freezer);
        }
        if (freezer.vida <= 0)
        {
            break;
        }
        if(!(rand() % 10)) {
            atacar(freezer, &goku);
        }
    }

    return 0;
}
