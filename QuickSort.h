#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "Sort.h"

class QuickSort : public Sort {
  public:
    QuickSort() { };
    virtual ~QuickSort() { };

    virtual void SortInt(int* array, int size);

  private:
    void SortInternal(int* array, int start, int end);
};

#endif // QUICKSORT_H_
