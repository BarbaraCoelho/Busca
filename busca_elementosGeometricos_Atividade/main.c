#include <stdio.h>
#include <stdlib.h>

typedef struct circulo Circulo;
struct circulo
{
    int raio;
    int cx;
    int cy;
};

int comp_circ_centro (const void * p1, const void * p2)
{

    const Circulo *f1 = p1;
    const Circulo *f2 = p2;
    if      (f1->cy < f2->cy) return -1;
    else if (f1->cy > f2->cy) return 1;
    else if (f1->cx < f2->cx) return -1;
    else if (f1->cx > f2->cx) return 1;
    else return 0;
}

int main()
{
    int i;
    Circulo *p;
    Circulo busca = {1,20,10};
    Circulo v[3]={{1,20,10},{2,2,2},{2,5,60}};
    //Ordeenação dos circulos
    qsort(v,3,sizeof(Circulo),comp_circ_centro);
    printf("Circulos ordenados: ");
    for (i=0; i<3; i++)
        printf("(%d,%d) ",v[i].cx,v[i].cy);
    printf("\n");
    //Busca Circulo
    p = bsearch(&busca,v,5,sizeof(Circulo),comp_circ_centro);
    if (p == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", p-v);
    return 0;
}
