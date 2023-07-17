#include "header.h"
void shell_sort_comp(int a[], int n, int &count_compare)
{
    int gap = 1;
    while (++count_compare && gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    while (++count_compare && gap >= 1)
    {
        for (int i = gap; ++count_compare, i < n; i++)
        {
            int key = a[i];
            int j = i;
            while (++count_compare && j >= gap && ++count_compare && a[j - gap] > key)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = key;
        }
        gap /= 3;
    }
}

void shell_sort_time(int a[], int n, long double &time_use)
{
    int count_compare = 0;
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
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
}

// void shell_sort2(int a[], int n)
// {
//     int gaps[] = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305, 260609 };
//     int gapIndex = sizeof(gaps) / sizeof(int) - 1;
//     while (gaps[gapIndex] >= n) {
//         gapIndex--;
//     }
//     for (int gap = gaps[gapIndex]; gap > 0; gap = gaps[--gapIndex])
//     {
//         for (int i = gap; i < n; i++)
//         {
//             int temp = a[i];
//             int j;
//             for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
//             {
//                 a[j] = a[j - gap];
//             }
//             a[j] = temp;
//         }
//     }
// }
