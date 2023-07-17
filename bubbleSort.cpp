#include "bubbleSort.h"
/*
 https://www.geeksforgeeks.org/bubble-sort/
 */
void bubble_sort_comp(int *arr, int n, int &count_comp)
{
    count_comp = 0;
    int i, j;
    // bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        // swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (++count_comp && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                // swapped = true;
            }
        }
        /*
         đây là bước cải tiến nếu không có phần tử nào được swap thì nó sẽ break
              if (swapped == false)
                  break;
         */
    }
    count_comp += (n - 1) * (n - 1);
}
void bubble_sort_time(int *arr, int n, long double &time)
{
    time = 0;
    clock_t start, end;
    start = clock();
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
