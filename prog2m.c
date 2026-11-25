
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int n = 1;
    int x;
    int i;
    int simm = 1;
    int *arr;

    // Открываем файл
    f = fopen("input_data.txt", "r");

    if (f == NULL) {
        printf("File error");
        return -1;
    }

    if (fscanf(f, "%d", &x) != 1)
    {
        printf("file is empty");
        fclose(f);
        return -3;
    }

    // Считаем количество элементов
    while (fscanf(f, "%d", &x) == 1) {
        n++;
    }

    // Выделяем память под массив
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("array error");
        fclose(f);
        return -2;
    }

    // Возвращаемся в начало файла
    rewind(f);

    // Записываем элементы в массив
    for (i = 0; i < n; i++) 
    {
        fscanf(f, "%d", &arr[i]);
    }

    fclose(f);

    // Проверяем симметричность массива
    for (i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            simm = 0;
            break;
        }
    }

    // Вывод результата
    if (simm == 1) {
        printf("symmetrical");
    } else {
        printf("not symmetrycal");
    }

    // Освобождаем память
    free(arr);

    return 0;
}
