#include "insertionSort.h"
void insertion_sort_comp(int a[], int n, int &count_compare)
{
    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;
        while (++count_compare && a[j] > key && ++count_compare && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    count_compare += n;
}
// void insertion_sort(int a[], int n)
//{
//     for (int i = 1; i < n; i++)
//     {
//         int key = a[i];
//         int j = i - 1;
//         while (a[j] > key && j >= 0)
//         {
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = key;
//     }
// }
void insertion_sort_time(int a[], int n, long double &time_use)
{
    clock_t start = clock();
    // insertion_sort(a, n);
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    clock_t end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
}
