#include <stdio.h>
int main() {
    FILE *file;
    int current, previous;
    int increasing = 1;
    int decreasing = 1;

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
        if (current <= previous) {
            increasing = 0;
        }

        if (current >= previous) {
            decreasing = 0;
        }

        previous = current;
    }

    fclose(file);

    if (increasing == 1) {
        printf("increasing");
    } 
    else if (decreasing == 1) {
        printf("decreasing");
    } 
    else {
        printf("not monotonous");
    }

    return 0;
}
