#include <stdio.h>
#include <stdlib.h>

typedef struct circulo Circulo;
struct circulo
{
    char *nome;
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

int  comp_circ_nome (const void *p1, const void *p2)
{
    const Circulo *f1 = p1;
    const Circulo *f2 = p2;
    if      (f1->nome < f2->nome) return -1;
    else if (f1->nome > f2->nome) return 1;
    else return 0;
}

int main()
{
    int i;
    Circulo *p;
    Circulo busca = {"c2",2,2};
    Circulo v[3]={{"c2",20,10},{"c3",5,60},{"c1",2,2}};
    //Ordeenação dos circulos
    qsort(v,3,sizeof(Circulo),comp_circ_nome);
    printf("Circulos ordenados nome: ");
    for (i=0; i<3; i++)
        printf("(%s) ",v[i].nome);
    printf("\n");
    //Busca Circulo
    p = bsearch(&busca,v,3,sizeof(Circulo),comp_circ_nome);
    if (p == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", p-v);
    return 0;
}
