#include "quickSort.h"

int partition_comp(int arr[], int low, int high, long long &count_comp)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (++count_comp && arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    count_comp += (high - low);
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort_comp_run(int arr[], int low, int high, long long &count_comp)
{
    if (++count_comp && low < high)
    {
        int pi = partition_comp(arr, low, high, count_comp);
        quick_sort_comp_run(arr, low, pi - 1, count_comp);
        quick_sort_comp_run(arr, pi + 1, high, count_comp);
    }
}
void quick_sort_comp(int arr[], int n, long long &count_comp)
{
    quick_sort_comp_run(arr, 0, n - 1, count_comp);
}

int partition_time(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quick_sort_time_run(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_time(arr, low, high);
        quick_sort_time_run(arr, low, pi - 1);
        quick_sort_time_run(arr, pi + 1, high);
    }
}

void quick_sort_time(int arr[], int n, long double &time)
{
    clock_t start, end;
    start = clock();
    quick_sort_time_run(arr, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}