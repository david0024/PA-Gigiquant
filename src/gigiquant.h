#include <stdio.h>
#include <stdlib.h>  
#include <math.h> 
struct Node {
    double valoare;
    double randament;
    struct Node* next;

};
typedef struct Node IND;

void AdaugareValori(IND **head, double valoare);
double RandamentMediu(IND *head, int n);
double Volatilitate(IND *head, int n);