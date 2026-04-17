#include "gigiquant.h"

int main(int argc, const *argv[])
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

    Task1(in, out);
    return 0;
}