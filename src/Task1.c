#include "gigiquant.h"
/*Task 1*/
void AdaugareValori(IND **head, double valoare)
{
    IND *newnode = (IND *)malloc(sizeof(IND));
    /// Verificare daca spatiul de memorie a fost alocat corect
    if (newnode == NULL)
    {
        perror("Eroare la alocarea de memorie");
        exit(1);
    }

    newnode->valoare = valoare;
    newnode->next = NULL;

    /// Daca lista este vida newnode va fi primul element
    if (*head == NULL)
    {
        newnode->randament = 0.0;
        *head = newnode;
    }
    else
    {
        /// In caz contrar, elementul va fi adaugat la finalul listei
        IND *aux = *head;

        while (aux->next != NULL)
            aux = aux->next;

        /// Valoarea randamentului este calculata direct din umplerea listei cu valori
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

    for (int i = 0; i < n - 1; i++)
    {
        randament_med += head->randament;
        head = head->next;
    }

    return randament_med / (double)(n - 1); /// N = numarul de randamente(n - 1)
}

double Volatilitate(IND *head, int n)
{
    double suma = 0.0;
    double miu = RandamentMediu(head, n);

    head = head->next;

    for (int i = 0; i < n - 1; i++)
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
    while (head != NULL)
    {
        IND *aux = head->next;
        free(head);
        head = aux;
    }
}

int Citire1(FILE *in, IND **head)
{
    int n;
    double valoare;

    if (fscanf(in, "%d", &n) != 1)
    {
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%lf", &valoare);
        AdaugareValori(head, valoare);
    }
    return n;
}
void Task1(FILE *in, FILE *out)
{

    IND *head = NULL;
    int n = Citire1(in, &head);
    /// Functia de trunchiere este folosita acum, in timpul afisarii; Daca era folosita inainte, ar fi fost afisat 0;
    fprintf(out, "%0.3lf\n", Trunchiere(RandamentMediu(head, n)));
    fprintf(out, "%0.3lf\n", Trunchiere(Volatilitate(head, n)));
    fprintf(out, "%0.3lf\n", Trunchiere(SharpeRatio(head, n)));

    EliberareSpatiu(head);
}
/*Task 2*/

double pop(SN **top) /// Folosita pentru a folosi valorile din cele 3 stive
{
    if (*top == NULL)
        return -1;
    SN *temp = *top;

    double valoare = temp->pret;

    *top = (*top)->next;
    free(temp);
    return valoare;
}

void EnQueue(Q *q, int zi, double diferenta, char *numeOras)
{
    OP *newOP = (OP *)malloc(sizeof(OP));
    if (newOP == NULL)
    {
        perror("Eroare");
        return;
    }

    newOP->zi = zi;
    newOP->diferenta = diferenta;
    strcpy(newOP->numeOras, numeOras);
    newOP->next = NULL;

    if (q->rear == NULL)
        q->rear = q->front = newOP;
    else
    {
        (q->rear)->next = newOP;
        q->rear = newOP;
    }
}
void push(SN **top, double valoare)
{
    SN *newNode = (SN *)malloc(sizeof(SN));
    newNode->pret = valoare;
    newNode->next = *top;
    *top = newNode;
}
int Citire2(FILE *in, SN **s1, SN **s2, SN **s3)
{
    char oras1[50], oras2[50], oras3[50];
    double valoare;
    int n1 = 0, n2 = 0, n3 = 0;

    /// Citire nume si valori oras 1
    if (fscanf(in, "%s", oras1) != 1)
        exit(1);

    while (fscanf(in, "%lf", &valoare) == 1)
    {
        push(s1, valoare);
        n1++;
    }

    /// Citire nume si valori oras 2
    if (fscanf(in, "%s", oras2) != 1)
        exit(1);

    while (fscanf(in, "%lf", &valoare) == 1)
    {
        push(s2, valoare);
        n2++;
    }

    /// Citire nume si valori oras 3

    if (fscanf(in, "%s", oras3) != 1)
        exit(1);

    while (fscanf(in, "%lf", &valoare) == 1)
    {
        push(s3, valoare);
        n3++;
    }

    int nr_zile = n1;
    if (n2 < nr_zile)
        nr_zile = n2;
    if (n3 < nr_zile)
        nr_zile = n3;
    return nr_zile;
}
