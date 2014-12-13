#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "Sort.h"

class InsertionSort : public Sort {
  public:
    InsertionSort() { };
    virtual ~InsertionSort() { };
    
    virtual void SortInt(int* array, int size);
};

#endif // INSERTIONSORT_H_
