#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "Sort.h"

#include <iostream>
#include <sys/time.h>

#define arraySize(array) sizeof(array) / sizeof(*array)

using namespace std;

struct AlgorithmType {
    int index;
    char name[32];
};

enum AlgorithmIndex {
    QUICK_SORT = 1,
    SELECTION_SORT,
    INSERTION_SORT,
    BUBBLE_SORT,
    MERGE_SORT,
};

const AlgorithmType kAlgorithms[] = {
    {QUICK_SORT, "Quick Sort"},
    {SELECTION_SORT, "Selection Sort"},
    {INSERTION_SORT, "Insertion Sort"},
    {BUBBLE_SORT, "Bubble Sort"},
    {MERGE_SORT, "Merge Sort"},
};

void SelectSortingAlgorithm(Sort** sort) {
    int type;
    for (int i = 0; i < arraySize(kAlgorithms); ++i)
        cout << kAlgorithms[i].index << ". " << kAlgorithms[i].name << endl;
    cout << "Select a sort algorthm: ";
    cin >> type;
    switch (type) {
    case QUICK_SORT:
        *sort = new QuickSort();
        break;
    case SELECTION_SORT:
        *sort = new SelectionSort();
        break;
    case INSERTION_SORT:
        *sort = new InsertionSort();
        break;
    case BUBBLE_SORT:
        *sort = new BubbleSort();
        break;
    case MERGE_SORT:
        *sort = new MergeSort();
        break;
    default:
        cout << "\nInvalid input! Please select again" << endl;
        SelectSortingAlgorithm(sort);
        break;
    }
}

int main() {
    Sort* sort;

    SelectSortingAlgorithm(&sort);

    int size;
    cout << "\nEnter number of elements: ";
    do {
        if (size < 0)
            cout << "Enter a valid number: ";
        cin >> size;
    } while (size < 0);

    int array[size];
    for (int i = 0; i < size; ++i)
        cin >> array[i];

    struct timeval dummyTime, startTime, endTime;
    gettimeofday(&dummyTime, NULL);
    gettimeofday(&startTime, NULL);
    {
        sort->SortInt(array, size);
    }
    gettimeofday(&endTime, NULL);
    int lag = startTime.tv_usec - dummyTime.tv_usec;
    long timeTaken = endTime.tv_usec - startTime.tv_usec - lag;

    cout << "\nArray sorted in:" << timeTaken << " micro secs." << endl;
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
