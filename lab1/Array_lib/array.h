#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../CException_lib/CException.h"     //lib для обработки исключений методом Try Catch

// множество для работы с исключениями
enum ERRORCODE_T
{
    NULL_POINTER,               //массив указывает на пустой указатель
    WRONG_ELEMENT_SIZE,         //длина элемента меньше 1
    WRONG_DIMENSION,            //длина массива меньше 1
    NO_COMPARATOR,              //отсутсвует функция сравнения
    DIFFERENT_ELEMENT_SIZE,     //разная длина элемента
    DIFFERENT_COMPARATOR        //разные функции сравнения
};

typedef struct {

    void *arr;                   //указатель на первый элемент
    size_t dimension;           //длина всего массива
    size_t elementSize;         //длина одного элемента

    int (*compare) (const void *left, const void *right);       //функция сравнения

} Array;

void intPrint(const Array *array);

void sort(Array *array);                                        //требуется массив, в котором обязательно присутствует функция сравнения
Array map(void (*func)(void *element), const Array *array);
void *reduce(void *(*func)(const void *first, const void *second), const Array *array, const void *start_element);
Array where(bool (*func)(const void *element), const Array *array);
Array concatenat(const Array* arr1, const Array* arr2);         //конкатенация

// функции сравнения
int intCompare(const int *left, const int *right);              //для int

#endif //ARRAY_H