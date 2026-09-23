#include <stdio.h>
int main() {
    FILE *file;
    int current, previous, length, max;
    length = 1;
    max = 0;
    file = fopen("input_data.txt", "r");

    if (file == NULL) {
        printf("err");
        return 1;
    }

    // Считываем первый элемент
    if (fscanf(file, "%d", &previous) != 1) {
        printf("file is empty");
        fclose(file);
        return 1;
    }

    // Считываем остальные элементы
    while (fscanf(file, "%d", &current) == 1) {
        if (current >= previous) {
            length = length + 1;
        }


        if (current <= previous) {
            length = 1;
        }

        if (length >= max) {
            max = length;
        }

        previous = current;

    }

    fclose(file);

    printf("%d", max);

    return 0;
}
