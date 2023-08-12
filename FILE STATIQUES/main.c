#include <stdio.h>
#include <stdlib.h>

/*
Nos fonctions :

- enfiler
- defiler
- estvide
- estpleine
- tete
...
*/
#define n 10
typedef struct files
{
    int t[n];
    int tete;
    int queue;
}files, *file;

int estvide(file f)
{
    if(f->tete == f->queue)
        return 1;
    return 0;
}

int estpleine(file f)
{
    if(f->tete == (f->queue+1)%n )
        return 1;
    return 0;
}

int tete(file f)
{
    if(estvide(f))
    {
        printf("Erreur : la file est vide");
        exit(0);
    }
    return f->t[f->tete];
}

void enfiler(file f, int x)
{
    if(estpleine(f))
    {
        printf("Erreur : la file est pleine");
        exit(0);
    }
    else{

        f->t[f->queue]= x;
        f->queue = (f->queue+1)%n;
    }
}
int defiler(file f)
{
    if(estvide(f))
    {
        printf("Erreur : la file est vide");
        exit(0);
    }
    else{

        int x = f->t[f->tete];
        f->tete = (f->tete+1)%n;
        return x;

    }
}

file initialiser()
{
    files *f=malloc(sizeof(*f));
    f->tete = 0;
    f->queue = 0;
    return f;
}

void afficher(file f)
{
    file f2 = initialiser();
    while(!estvide(f))
    {
        int x = defiler(f);
        printf("%d\n",x);
        enfiler(f2,x);
    }
    while(!estvide(f2))
    {
        int x = defiler(f2);
        enfiler(f,x);
    }

}



int main()
{
    file f = initialiser();
    enfiler(f,7);
    enfiler(f,4);
    enfiler(f,8);
    enfiler(f,7);
    enfiler(f,9);
    printf("\n---\n");
    afficher(f);
    printf("\n---\n");

    printf("la tete est : %d",tete(f));
    defiler(f);

    printf("\n---\n");
    afficher(f);
    printf("la tete est : %d",tete(f));



    return 0;
}
