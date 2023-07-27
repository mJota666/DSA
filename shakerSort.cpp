#include "shakerSort.h"
void shaker_sort_comp(int a[], int n, long long &count_comp)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (++count_comp&&Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (++count_comp&&(a[i] > a[i + 1]))
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        count_comp += (Right - Left + 1);
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (++count_comp&&(a[i] < a[i - 1]))
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        count_comp += (Right - Left + 1);
        Left = k;
    }
}
void shaker_sort_time(int *a, int n, long double &time)
{
    time = 0;
    clock_t start, end;
    start = clock();
    int Left = 0;
        int Right = n - 1;
        int k = 0;
        while (Left < Right)
        {
            for (int i = Left; i < Right; i++)
            {
                if (a[i] > a[i + 1])
                {
                    swap(a[i], a[i + 1]);
                    k = i;
                }
            }
            Right = k;
            for (int i = Right; i > Left; i--)
            {
                if (a[i] < a[i - 1])
                {
                    swap(a[i], a[i - 1]);
                    k = i;
                }
            }
            Left = k;
        }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
