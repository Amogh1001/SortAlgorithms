#ifndef ALGORITHM_DETAILS_H_
#define ALGORITHM_DETAILS_H_

struct AlgorithmDetail {
    int index;
    char name[32];
};

enum AlgorithmIndex {
    QUICK_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    BUBBLE_SORT,
    MERGE_SORT,
};

const AlgorithmDetail kAlgorithms[] = {
    {QUICK_SORT, "Quick Sort"},
    {SELECTION_SORT, "Selection Sort"},
    {INSERTION_SORT, "Insertion Sort"},
    {BUBBLE_SORT, "Bubble Sort"},
    {MERGE_SORT, "Merge Sort"},
};

#endif // ALGORITHM_DETAILS_H_
