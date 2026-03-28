#include "gigiquant.h"

int main(int argc, char *argv[])
{
    FILE *in, *out;
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
    fprintf(out, "%0.3lf\n", RandamentMediu(head, n));
    fprintf(out, "%0.3lf\n", Volatilitate(head, n));   
    fprintf(out, "%0.3lf\n", SharpeRatio(head, n)); 
    return 0;
}