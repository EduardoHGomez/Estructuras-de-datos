#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 20

struct STRNODE {
    int num;
    struct STRNODE *next;
};

typedef struct {
    struct STRNODE *first;
    struct STRNODE *last;
} LIST;

#define LISTINIT {NULL,NULL}

void insert(LIST *list,int num);
int found(LIST list,int num);
void display(LIST list);
void destroy(LIST list);

int main()
{
    srand(time(NULL));

    LIST l = LISTINIT; // Establece first y last como NULL
    int n;

    for(int i = 0; i<LIMIT; i++)
    {
        n = rand() % LIMIT;
        printf("i: %d Numero aleatorio: %d\n", i, n);

        insert(&l,n);

        
    }
    

    printf("Lista almacenada: \n");
    display(l);
    
}

void insert(LIST *l, int n)
{
    
    if (l->first == NULL) // Si es el primero
    {
        l->first = malloc(sizeof(struct STRNODE));
        l->first->num = n;
        l->first->next = NULL;
    }
    else
    {
        struct STRNODE *ptr = l->first;

        while (ptr != NULL)
        {
            ptr = ptr->next;
        }

        ptr = malloc(sizeof(struct STRNODE));
        ptr->num = n;
        ptr->next = NULL;
        l->last = ptr;
        
    }
}

int found(LIST list,int num)
{
    struct STRNODE *ptr = list.first;

    while (ptr != NULL)
    {
        if (ptr->num == num)
        {
            return 1;
        }
        
        ptr = ptr->next;
    }

    return 0;
}

void display(LIST list)
{
    struct STRNODE *ptr = list.first;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->num);
        ptr = ptr->next;
    }
    
}

void destroy(LIST list)
{
    struct STRNODE *ptr = list.first;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }
    
}