#include "function.h"
#include <iostream>
#include <ctime>

using namespace std;

pBiTree addNumber(pBiTree biTree, int number) {
    if (biTree == nullptr)
    {
        biTree = new biTreeSearch;
        biTree->number = number;
        biTree->left = nullptr;
        biTree->right = nullptr;
    } else if (number < biTree->number)
        biTree->left = addNumber(biTree->left, number);
    else
        biTree->right = addNumber(biTree->right, number);

    return(biTree);
}

void heapSort()
{
    int size;
    srand (time(nullptr));

    cout << "\nEnter the number of numbers: ";
    cin >> size;

    int *array = new int[size];

    cout << endl;
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100 + 1;

    cout << "Original array:\n";
    printArray(array, size);

    sortPyramid(array, size);

    cout << "\nSorted array:\n";
    printArray(array, size);

    freeMemoryHeap(array);
    cout << "\nMemory released\n";

}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

void sortPyramid(int *array, int size)
{
    for (int i = (size/2); i > -1; i--)
        sifting(array, i, size - 1);

    for (int i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        sifting(array, 0, i - 1);
    }
}

void sifting(int *array, int root, int bottom)
{
    int max;
    int f = 0;


    while ((root*2 <= bottom) && (!f))
    {
        if (root*2 == bottom)
            max = root*2;
        else if (array[root*2] > array[root*2 + 1])
            max = root*2;
        else
            max = root*2 + 1;
        if (array[root] < array[max])
        {
            int temp = array[root];
            array[root] = array[max];
            array[max] = temp;
            root = max;
        }
        else
            f = 1;
    }
}

void freeMemoryHeap(const int *array)
{
    delete[] array;
}
