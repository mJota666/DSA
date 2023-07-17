#include "shellSort.h"

void shell_sort_comp(int a[], int n, long long &count_comp)
{
    int gap = 1;
    while (++count_comp && gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    while (++count_comp && gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int key = a[i];
            int j = i;
            while (++count_comp && j >= gap && ++count_comp && a[j - gap] > key)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = key;
        }
        count_comp += (n - gap) + 1;
        gap /= 3;
    }
}

void shell_sort_time(int a[], int n, long double &time)
{
    clock_t start = clock();
    int gap = 1;
    while (gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int key = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > key)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = key;
        }
        gap /= 3;
    }
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
