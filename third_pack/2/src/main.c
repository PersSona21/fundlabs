#include "../include/main.h"

void *copyInt(void *p) {
    int *v = malloc(sizeof(int));
    if (!v) exit(EXIT_FAILURE);
    *v = *(int*)p;
    return v;
}

void deleteInt(void *p) {
    free(p);
}

void printIntVector(const Vector *v) {
    printf("[ ");
    for (size_t i = 0; i < v->size; i++) {
        int *val = (int*)get_at_vector(v, i);
        printf("%d ", *val);
    }
    printf("]\n");
}

int main(int argc, char *argv[]) {
    printf("=== Создание вектора ===\n");
    Vector v = create_vector(2, copyInt, deleteInt);

    printf("=== Добавление элементов ===\n");
    int a = 10, b = 20, c = 30;
    push_back_vector(&v, &a);
    push_back_vector(&v, &b);
    push_back_vector(&v, &c);
    printIntVector(&v);

    printf("=== Получение элемента по индексу 1 ===\n");
    int *val = get_at_vector(&v, 1);
    printf("v[1] = %d\n", *val);

    printf("=== Удаление элемента по индексу 1 ===\n");
    delete_at_vector(&v, 1);
    printIntVector(&v);

    printf("=== Копирование вектора в существующий ===\n");
    Vector v2 = create_vector(0, copyInt, deleteInt);
    copy_vector(&v2, &v);
    printIntVector(&v2);

    printf("=== Создание нового вектора через copy_vector_new ===\n");
    Vector *v3 = copy_vector_new(&v);
    printIntVector(v3);

    printf("=== Сравнение векторов ===\n");
    printf("v == v2 ? %s\n", is_equal_vector(&v, &v2) ? "Да" : "Нет");
    printf("v == v3 ? %s\n", is_equal_vector(&v, v3) ? "Да" : "Нет");

    printf("=== Очистка векторов ===\n");
    erase_vector(&v);
    erase_vector(&v2);
    delete_vector(v3); // освобождает память v3 и его элементы
    return OK;
}
