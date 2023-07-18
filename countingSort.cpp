#include "countingSort.h"

int max_value_comp(int *arr, int n, long long &count_comp)
{
    int max_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (++count_comp && arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    count_comp += n;
    return max_value;
}
void counting_sort_comp(int *arr, int capacity, long long &count_comp)
{
    int RANGE = max_value_comp(arr, capacity, count_comp);
    int *output = new int[capacity];
    int *count = new int[RANGE + 1];
    memset(count, 0, (RANGE + 1) * sizeof(int));
    for (int i = 0; i < capacity; ++i)
    {
        ++count[arr[i]];
    }
    count_comp += (capacity + 1);
    for (int i = 1; i <= RANGE; ++i)
    {
        count[i] += count[i - 1];
    }
    count_comp += (RANGE + 1);
    for (int i = capacity - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    count_comp += (capacity + 1);
    delete[] output;
    delete[] count;
}
int max_value(int *arr, int n)
{
    int max_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    return max_value;
}
void counting_sort_time(int *arr, int capacity, long double &time)
{
    clock_t start, end;
    start = clock();
    int RANGE = max_value(arr, capacity);
    int *output = new int[capacity];
    int *count = new int[RANGE + 1];
    memset(count, 0, (RANGE + 1) * sizeof(int));
    for (int i = 0; i < capacity; ++i)
    {
        ++count[arr[i]];
    }
    for (int i = 1; i <= RANGE; ++i)
    {
        count[i] += count[i - 1];
    }
    for (int i = capacity - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    delete[] output;
    delete[] count;
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
