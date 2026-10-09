
#include <stdio.h>
#include <math.h>

#define EPS 1.e-10

int count_elements(FILE *f)
{
    double first = 0.0;
    double second = 0.0;
    double current = 0.0;
    int sum = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        printf("File is empty\n");
        return 0;
    }

    if (fscanf(f, "%lf", &second) != 1)
    {
        printf("No second element\n");
        return 0;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (fabs(current - first) < EPS)
        {
            sum++;
        }

        if (fabs(current - second) < EPS)
        {
            sum--;
        }
    }

    if (sum > 0)
    {
        return 1;
    }
    else if (sum < 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }

    int answer = count_elements(f);

    if (answer == 1)
    {
        printf("More elements which are equal to the first one\n");
    }
    else if (answer == 2)
    {
        printf("More elements which are equal to the second one\n");
    }
    else if (answer == 3)
    {
        printf("Equal number of elements\n");
    }

    fclose(f);

    return 0;
}
