#include <cstdlib>
#include <cstring>

struct biTreeSearch
{
    int number;
    biTreeSearch *left, *right;

} typedef *pBiTree;

void heapSort();
void printArray(int *array, int size);
void sortPyramid(int *array, int size);
void sifting(int *array, int root, int bottom);
void freeMemoryHeap(const int *array);
