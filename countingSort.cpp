#include  "header.h"
#define RANGE 255
void counting_sort_comp(int *arr, int capacity, int &count_comp)
{
    count_comp = 0;
    int *output = new int[capacity];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; ++count_comp && arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1; ++count_comp && i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; ++count_comp && arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    delete []output;
}

void counting_sort_time(int *arr, int capacity, long double &time){
    time = 0;
    clock_t start, end;
    start = clock();
    int *output = new int[capacity];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0;  arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1;  i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    delete []output;
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC ;
}
