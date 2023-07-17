#include "mergeSort.h"

void merge(int a[], int leftIndex, int midIndex, int rightIndex)
{
    int sizeOfLeftArray = (midIndex - leftIndex) + 1;
    int sizeOfRightArray = (rightIndex - midIndex);
    int *leftArray = new int[sizeOfLeftArray];
    int *rightArray = new int[sizeOfRightArray];
    memcpy(leftArray, a + leftIndex, sizeOfLeftArray * sizeof(int));
    memcpy(rightArray, a + midIndex + 1, sizeOfRightArray * sizeof(int));
    int i = 0;
    int j = 0;
    while (i < sizeOfLeftArray && j < sizeOfRightArray)
    {
        if (leftArray[i] <= rightArray[j])
        {
            a[leftIndex++] = leftArray[i++];
        }
        else
        {
            a[leftIndex++] = rightArray[j++];
        }
    }
    while (i < sizeOfLeftArray)
    {
        a[leftIndex++] = leftArray[i++];
    }
    while (j < sizeOfRightArray)
    {
        a[leftIndex++] = rightArray[j++];
    }
    delete[] leftArray;
    delete[] rightArray;
}

void merge_sort(int a[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int midIndex = (leftIndex + rightIndex) / 2;
        merge_sort(a, leftIndex, midIndex);
        merge_sort(a, midIndex + 1, rightIndex);
        merge(a, leftIndex, midIndex, rightIndex);
    }
}

void merge_comp_run(int a[], int leftIndex, int midIndex, int rightIndex, long long &count_comp)
{
    int sizeOfLeftArray = (midIndex - leftIndex) + 1;
    int sizeOfRightArray = (rightIndex - (midIndex + 1)) + 1;
    int *leftArray = new int[sizeOfLeftArray];
    int *rightArray = new int[sizeOfRightArray];
    memcpy(leftArray, a + leftIndex, sizeOfLeftArray * sizeof(int));
    memcpy(rightArray, a + midIndex + 1, sizeOfRightArray * sizeof(int));
    int i = 0;
    int j = 0;
    while (++count_comp && i < sizeOfLeftArray && ++count_comp && j < sizeOfRightArray)
    {
        ++count_comp;
        if (leftArray[i] < rightArray[j])
        {
            a[leftIndex++] = leftArray[i++];
        }
        else
        {
            a[leftIndex++] = rightArray[j++];
        }
    }
    while (++count_comp && i < sizeOfLeftArray)
    {
        a[leftIndex++] = leftArray[i++];
    }
    while (++count_comp && j < sizeOfRightArray)
    {
        a[leftIndex++] = rightArray[j++];
    }
    delete []leftArray;
    delete []rightArray;
}

void merge_sort_comp_run(int a[], int leftIndex, int rightIndex, long long &count_comp)
{
    if (++count_comp && leftIndex < rightIndex)
    {
        int midIndex = (leftIndex + rightIndex) / 2;
        merge_sort_comp_run(a, leftIndex, midIndex, count_comp);
        merge_sort_comp_run(a, midIndex + 1, rightIndex, count_comp);
        merge_comp_run(a, leftIndex, midIndex, rightIndex, count_comp);
    }
}
void merge_sort_comp(int a[], int n, long long &count_comp)
{
    merge_sort_comp_run(a, 0, n - 1, count_comp);
}

void merge_sort_time(int a[], int n, long double &time)
{
    clock_t start = clock();
    merge_sort(a, 0, n - 1);
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
