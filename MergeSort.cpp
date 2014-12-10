#include "MergeSort.h"

void MergeSort::SortInt(int* array, int size) {
    int temp[size];
    TopDownSplitMerge(array, 0, size, temp);
}

void MergeSort::TopDownSplitMerge(int* array, int begin, int end, int* temp) {
    if ((end - begin) < 2)
        return;

    int middle = (begin + end) / 2;
    TopDownSplitMerge(array, begin, middle, temp);
    TopDownSplitMerge(array, middle, end, temp);
    TopDownMerge(array, begin, middle, end, temp);
    copyArray(temp, begin, end, array);
}

void MergeSort::TopDownMerge(int* array, int begin, int middle, int end, int* temp) {
    int midOriginal = middle;
    for (int i = begin; i < end; ++i) {
        if (begin < midOriginal && (middle >= end || array[begin] <= array[middle]))
            temp[i] = array[begin++];
        else
            temp[i] = array[middle++];
    }
}

void MergeSort::copyArray(int* temp, int begin, int end, int* array) {
    for (int i = begin; i < end; ++i)
        array[i] = temp[i];
}
