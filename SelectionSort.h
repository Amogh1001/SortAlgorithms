#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "Sort.h"

class SelectionSort : public Sort {
  public:
    SelectionSort() { };
    virtual ~SelectionSort() { };
    
    virtual void SortInt(int* array, int size);

  private:
    void SwapArrayValuesAt(int* array, int i, int j);
};

#endif // SELCTIONSORT_H_
