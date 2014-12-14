#include "../src/AlgorithmDetails.h"
#include "../src/BubbleSort.h"
#include "../src/InsertionSort.h"
#include "../src/MergeSort.h"
#include "../src/QuickSort.h"
#include "../src/SelectionSort.h"
#include "../src/Sort.h"

#include <iostream>

using namespace std;

#define arraySize(array) sizeof(array) / sizeof(*array)

const int kTestCaseSize = 32;

const int kTestCases[][kTestCaseSize] = {
    {1},
    {2, 1},
    {1, 3, 2},
    {1, 4, 3, 2},
    {1, 1, 1, 1, 1},
    {1, 2, 3, 4, 5, 6},
    {3, 4, 6, 1, 4, 7, 8, 3, 7, 12, 23, 46, 12, 11, 34},
    {34, 12, 16, 15, 73, 73, 123, 57, 23, 65, 55, 88, 1212}
};

bool IsSorted(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[i - 1])
            return false;
    }
    return true;
}

void RunTests(Sort* sort) {
    for (int i = 0; i < arraySize(kTestCases); ++i) {
        int tempArray[kTestCaseSize];
        for (int j = 0; j < kTestCaseSize; ++j)
            tempArray[j] = kTestCases[i][j];

        sort->SortInt(tempArray, kTestCaseSize);
        if (!IsSorted(tempArray, kTestCaseSize)) {
            cout << "Test " << i << " failed." << endl;
            return;
        }
    }
    cout << "All tests ran expectedy" << endl;
}

int main() {
    Sort* sort;
    for (int i = 0; i < arraySize(kAlgorithms); ++i) {
        sort = NULL;
        switch (i) {
        case QUICK_SORT:
            sort = new QuickSort();
            break;
        case SELECTION_SORT:
            sort = new SelectionSort();
            break;
        case INSERTION_SORT:
            sort = new InsertionSort();
            break;
        case BUBBLE_SORT:
            sort = new BubbleSort();
            break;
        case MERGE_SORT:
            sort = new MergeSort();
            break;
        default:
            break;
        }
        cout << kAlgorithms[i].name << " - ";
        RunTests(sort);
    }
}
