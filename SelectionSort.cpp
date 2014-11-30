#include "SelectionSort.h"

void SelectionSort::SortInt(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        int minIndex = i;
        for (int j = i; j < size; ++j) {
            if (array[minIndex] > array[j])
                minIndex = j;
        }
        if (i != minIndex)
            SwapArrayValuesAt(array, i, minIndex);
    }
}

void SelectionSort::SwapArrayValuesAt(int* array, int i, int j) {
    // Swapping without any new variable.
    array[i] = array[i] - array[j];
    array[j] = array[j] + array[i];
    array[i] = array[j] - array[i];
}
