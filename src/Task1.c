#include "gigiquant.h"

void AdaugareValori(IND **head, double valoare)
{
    IND *newnode = (IND*)malloc(sizeof(IND));

    newnode->valoare = valoare;
    newnode->next = NULL;
    if(newnode == NULL)
    {
        perror("Eroare la alocarea de memorie");
        exit(1);
    }

    if(*head == NULL)
    {
        newnode->randament = 0.0;
        *head = newnode;
        
    }
    else {
        
        IND *aux = *head;
        
        while(aux->next != NULL)
            aux = aux->next;

        newnode->randament = (newnode->valoare - aux->valoare) / aux->valoare;
        aux->next = newnode;
    }
}

double RandamentMediu(IND *head, int n)
{
    double randament_med = 0.0;
    for (int i = 0; i < n; i ++)
    {
        randament_med += head->randament;
        head = head->next;
    }
    
    return (randament_med/(1.0*n));
}

double Volatilitate(IND *head, int n)
{
    double suma = 0.0;
    double miu = RandamentMediu(head, n);
    for(int i = 0; i < n; i ++)
    {
        suma += (head->randament - miu) * (head->randament - miu);
        head = head->next;
    }
    suma /= n;
    suma = (double)(sqrt(suma));
    return suma;
}