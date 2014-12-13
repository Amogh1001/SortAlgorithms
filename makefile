CC=g++
EXEC=Sort

all: Sort

Sort: Main.o BubbleSort.o InsertionSort.o MergeSort.o QuickSort.o SelectionSort.o
	$(CC) Main.o BubbleSort.o InsertionSort.o MergeSort.o QuickSort.o SelectionSort.o -o $(EXEC)

Main.o: Main.cpp
	$(CC) -c Main.cpp

BubbleSort.o: BubbleSort.cpp
	$(CC) -c BubbleSort.cpp

InsertionSort.o: InsertionSort.cpp
	$(CC) -c InsertionSort.cpp

MergeSort.o: MergeSort.cpp
	$(CC) -c MergeSort.cpp

QuickSort.o: QuickSort.cpp
	$(CC) -c QuickSort.cpp

SelectionSort.o: SelectionSort.cpp
	$(CC) -c SelectionSort.cpp

clean:
	rm *o Sort