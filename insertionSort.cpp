#include "insertionSort.h"
void insertion_sort_comp(int a[], int n, long long &count_comp)
{
    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;
        while (++count_comp && a[j] > key && ++count_comp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    count_comp += n;
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
void insertion_sort_time(int a[], int n, long double &time)
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
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
