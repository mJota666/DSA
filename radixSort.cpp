#include "header.h"

using namespace std;

/*
https://www.geeksforgeeks.org/radix-sort/
*/

void radix_sort(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        int* output = new int[n];
        int i, count[10] = { 0 };

        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
        delete[]output;
    }
}

void radix_sort_comp(int arr[], int n, int& count_compare)
{
    count_compare = 0;
    int mx = arr[0];
    for (int i = 1; ++count_compare, i < n; i++)
        if (++count_compare && arr[i] > mx)
            mx = arr[i];

    for (int exp = 1; ++count_compare, mx / exp > 0; exp *= 10)
    {
        int* output = new int[n];
        int i, count[10] = { 0 };

        for (i = 0; ++count_compare, i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; ++count_compare, i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; ++count_compare, i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; ++count_compare, i < n; i++)
            arr[i] = output[i];
        delete[]output;
    }
}

void radix_sort_time(int arr[], int n, long double& time)
{
    clock_t start, end;

    start = clock();
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        int* output = new int[n];
        int i, count[10] = { 0 };

        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
        delete[]output;
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
