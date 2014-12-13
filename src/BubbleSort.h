#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include "Sort.h"

class BubbleSort : public Sort {
  public:
    BubbleSort() { }
    virtual ~BubbleSort() { }

    void SortInt(int* array, int size);

  private:
    void SwapArrayValuesAt(int* array, int i, int j);
};

#endif // BUBBLESORT_H_
