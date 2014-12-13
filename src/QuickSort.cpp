#include "QuickSort.h"

void QuickSort::SortInt(int* array, int size) {
    SortInternal(array, 0, size - 1);
}

void QuickSort::SortInternal(int* array, int start, int end) {
    if (end <= start)
        return;

    int size = end - start + 1;
    int pivot = start + (size / 2);
    int tempArray[size];
    int leftNumber = 0, rightNumber = size;

    for (int i = start; i <= end; ++i) {
        if (i == pivot)
            continue;
        if (array[i] <= array[pivot])
            tempArray[leftNumber++] = array[i];
        else if (array[i] > array[pivot])
            tempArray[--rightNumber] = array[i];
    }
    tempArray[leftNumber] = array[pivot];

    for (int i = 0; i < size; ++i)
        array[start + i] = tempArray[i];

    SortInternal(array, start, start + leftNumber - 1);
    SortInternal(array, start + leftNumber + 1, end);
}
