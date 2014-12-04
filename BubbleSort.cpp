#include "BubbleSort.h"

void BubbleSort::SortInt(int* array, int size) {
    bool swapped = false;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            SwapArrayValuesAt(array, i, i + 1);
            swapped = true;
        }
    }
    if (swapped)
        SortInt(array, size);    
}

void BubbleSort::SwapArrayValuesAt(int* array, int i, int j) {
    // Swapping without any new variable.
    array[i] = array[i] - array[j];
    array[j] = array[j] + array[i];
    array[i] = array[j] - array[i];
}
