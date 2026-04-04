#include "gigiquant.h"

int main(int argc, char *argv[])
{
    FILE *in, *out; /// Fisiere pentru intrare si iesire
    in = fopen(argv[1], "r");
    if(in == NULL)
    {
        perror("Error");
        exit(1);
    }

    out = fopen(argv[2], "w");
    if(out == NULL)
    {
        perror("Error");
        exit(1);
    }


    IND *head = NULL;
    int n;
    double valoare;

    fscanf(in, "%d", &n);

    for(int i = 0; i < n; i ++)
        {
            fscanf(in, "%lf", &valoare);
            AdaugareValori(&head, valoare);
        }
    ///Functia de trunchiere este folosita acum, in timpul afisarii; Daca era folosita inainte, ar fi fost afisat 0;
    fprintf(out, "%0.3lf\n", Trunchiere(RandamentMediu(head, n)));
    fprintf(out, "%0.3lf\n", Trunchiere(Volatilitate(head, n)));   
    fprintf(out, "%0.3lf\n", Trunchiere(SharpeRatio(head, n))); 

    EliberareSpatiu(head);
    return 0;
}