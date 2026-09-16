#include <stdio.h>

int count_elements(FILE *f)
{
    double fi = 0., s = 0., current = 0.;
    int sum1 = 0, sum2 = 0;

    if (fscanf(f, "%lf", &fi) != 1)
    {
        printf("File is empty");
        return 0;
    }

    if (fscanf(f, "%lf", &s) != 1)
    {
        printf("No second elemet");
        return 0;
    }

    sum1 = 1;
    sum2 = 1;

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (current == fi)
            sum1 += sum1 + 1;

        if (current == s)
            sum2 += sum2 + 1;
    }

    if (sum1 > sum2)
        return 1;
    else if (sum2 > sum1)
        return 2;
    else
        return 3;
}

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("File error");
        return -1;
    }
    else
    {
        int answer = count_elements(f);

        if (answer == 1)
            printf("More elements which are equal to a first one");
        else if (answer == 2)
            printf("More elements which are equal to a second one");
        else if (answer == 3)
            printf("equal");
    }

    fclose(f);
    return 0;
}
