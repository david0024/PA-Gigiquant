#include "gigiquant.h"

void AdaugareValori(IND **head, double valoare)
{
    IND *newnode = (IND*)malloc(sizeof(IND));

    newnode->valoare = valoare;
    newnode->next = NULL;
    ///Verificare daca spatiul de memorie a fost alocat corect
    if(newnode == NULL)
    {
        perror("Eroare la alocarea de memorie");
        exit(1);
    }

    ///Daca lista este vida newnode va fi primul element
    if(*head == NULL)
    {
        newnode->randament = 0.0;
        *head = newnode;
        
    }
    else {
        ///In caz contrar, elementul va fi adaugat la finalul listei
        IND *aux = *head;
        
        while(aux->next != NULL)
            aux = aux->next;

        ///Valoarea randamentului este calculata direct din umplerea listei cu valori
        newnode->randament = (newnode->valoare - aux->valoare) / aux->valoare;

        aux->next = newnode;
    }
}


double Trunchiere(double x) /// Trunchierea se face la final, in afisare, pentru a afisa valorile exacte
{
    /// Returneaza valoarea cu exact 3 zecimale
    return trunc(1000 * x) / 1000;
}

double RandamentMediu(IND *head, int n)
{
    double randament_med = 0.0;
    
    head = head->next; /// Nu se ia in considerare primul element

    for (int i = 0; i < n - 1; i ++)
    {
        randament_med += head->randament;
        head = head->next;
    }
    
    return randament_med/(double)(n - 1); /// N = numarul de randamente(n - 1)
}

double Volatilitate(IND *head, int n)
{
    double suma = 0.0;
    double miu = RandamentMediu(head, n);
    
    head = head->next;
    
    for(int i = 0; i < n - 1; i ++)
    {
        suma += (head->randament - miu) * (head->randament - miu); 
        head = head->next;
    }
    
    suma /= (n - 1); /// La fel ca in cazul randamentului, suma se imparte la numarul de randamente
    suma = (double)(sqrt(suma));
    return suma;
}

double SharpeRatio(IND *head, int n)
{
    double SR;
    SR = RandamentMediu(head, n) / Volatilitate(head, n);
    return SR;
}

void EliberareSpatiu(IND *head)
{
    while(head != NULL)
    {
        IND* aux = head->next;
        free(head);
        head = aux;
    }
}