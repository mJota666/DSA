#include "heapSort.h"

int max_comp(int a[], int x, int y, int &count_comp)
{
    count_comp++;
    return a[x] >= a[y] ? x : y;
}

void heap_rebuild_comp(int a[], int n, int pos, int &count_comp)
{
    int k = pos;
    bool isHeap = false;
    while (++count_comp && 2 * k + 1 < n && isHeap == false)
    {
        int j = 2 * k + 1;
        if (++count_comp && j < n - 1)
        {
            j = max_comp(a, j, j + 1, count_comp);
        }
        if (++count_comp && a[j] > a[k])
        {
            swap(a[j], a[k]);
            k = j;
        }
        else
        {
            isHeap = true;
        }
    }
}
void build_heap_comp(int a[], int n, int &count_comp)
{
    int i = n / 2 - 1;

    while (++count_comp && i >= 0)
    {
        heap_rebuild_comp(a, n, i, count_comp);
        i--;
    }
}

void heap_sort_comp(int a[], int n, int &count_comp)
{
    count_comp = 0;
    build_heap_comp(a, n, count_comp);
    while (++count_comp && n > 0)
    {
        swap(a[n - 1], a[0]);
        n--;
        heap_rebuild_comp(a, n, 0, count_comp);
    }
}

// time

int max_time(int a[], int x, int y)
{
    return a[x] >= a[y] ? x : y;
}

void heap_rebuild_time(int a[], int n, int pos)
{
    int k = pos;
    bool isHeap = false;
    while (2 * k + 1 < n && isHeap == false)
    {
        int j = 2 * k + 1;
        if (j < n - 1)
        {
            j = max_time(a, j, j + 1);
        }
        if (a[j] > a[k])
        {
            swap(a[j], a[k]);
            k = j;
        }
        else
        {
            isHeap = true;
        }
    }
}
void build_heap_time(int a[], int n)
{
    int i = n / 2 - 1;

    while (i >= 0)
    {
        heap_rebuild_time(a, n, i);
        i--;
    }
}

void heap_sort_time(int a[], int n, long double &time)
{
    time = 0;
    clock_t start, end;
    start = clock();
    build_heap_time(a, n);
    while (n > 0)
    {
        swap(a[n - 1], a[0]);
        n--;
        heap_rebuild_time(a, n, 0);
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
