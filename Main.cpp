#include "QuickSort.h"
#include "Sort.h"
#include <iostream>

using namespace std;

enum SortingAlgorithms {
    QUICK_SORT = 1,
};

void SelectSortingAlgorithm(Sort** sort) {
    int type;
    cout << "1. Quick Sort\nSelect a sorting algorithm: ";
    cin >> type;
    switch (type) {
    case QUICK_SORT:
        *sort = new QuickSort();
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

    sort->SortInt(array, size);

    cout << "\nSorted array is:" << endl;
    for (int i = 0; i < size; ++i)
        cout << array[i] << endl;
}
