#include <stdio.h>
#include <stdlib.h>  
#include <math.h> 
typedef struct Node {
    double valoare;
    double randament;
    struct Node* next;

}IND;

typedef struct StackNode{
    double pret;
    struct StackNode *next;
}SN;

typedef struct Oportunitate{
    int zi;
    double diferenta;
    char numeOras[30];
    struct Oportunitate *next;
       
}OP;

typedef struct Queue{
    OP *front, *rear;
}Q;

void AdaugareValori(IND **head, double valoare);
double RandamentMediu(IND *head, int n);
double Volatilitate(IND *head, int n);
double SharpeRatio(IND *head, int n);
double Trunchiere(double x);
void EliberareSpatiu(IND *head);
int Citire1(FILE* in, IND **head);
void Task1(FILE *in, FILE *out);
int Citire2(FILE *in, SN **s1, SN **s2, SN **s3);
void Task2(SN **s1, SN **s2, SN **s3, Q *q, char *oras1, char *oras2, char *oras3, int nr_zile);
void Afisare(Q *q, FILE *out);
void push(SN **top, double valoare);
double pop(SN **top);
void EnQueue(Q *q, int zi, double diferenta, char *numeOras);