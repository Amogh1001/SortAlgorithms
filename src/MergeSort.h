#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "Sort.h"

class MergeSort : public Sort {
  public:
    MergeSort() { }
    virtual ~MergeSort() { }

    virtual void SortInt(int* array, int size);

  private:
    void TopDownSplitMerge(int* array, int begin, int end, int* temp);
    void TopDownMerge(int* array, int begin, int middle, int end, int* temp);
    void copyArray(int* temp, int begin, int end, int* array);
};

#endif // MERGESORT_H_
