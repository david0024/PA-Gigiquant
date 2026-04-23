#include "gigiquant.h"

int main(int argc, char *argv[])
{
    FILE *in, *out; /// Fisiere pentru intrare si iesire
    int valoareTask;
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

    valoareTask = ValoareTask(argv[1]);
    if(valoareTask >= 1 && valoareTask <= 5)
    {
        Task1(in, out);
    }
    else if (valoareTask >= 6 && valoareTask <= 10)
    {
       Task2(in, out); 
    }
    return 0;
}