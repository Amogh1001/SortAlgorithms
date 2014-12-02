#include "InsertionSort.h"

void InsertionSort::SortInt(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        int temp = array[i];
        for (; j > 0 && array[j - 1] > temp; --j)
            array[j] = array[j - 1];
        array[j] = temp;
    }
}
