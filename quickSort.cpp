#include "quickSort.h"
struct StackElement {
    int start;
    int end;
};

int find_median(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[low])
        swap(arr[mid], arr[low]);
    if (arr[high] < arr[low])
        swap(arr[high], arr[low]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    return arr[high];
}

int partition(int arr[], int low, int high) {
    int pivot = find_median(arr, low, high);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    StackElement* stack = new StackElement[high - low + 1];
    int top = -1;

    stack[++top] = { (low, high) };

    while (top >= 0) {
        high = stack[top].end;
        low = stack[top--].start;

        while (low < high) {
            int pivotIndex = partition(arr, low, high);

            if (pivotIndex - low < high - pivotIndex) {
                stack[++top] = { pivotIndex + 1, high };
                high = pivotIndex - 1;
            } else {
                stack[++top] = { low, pivotIndex - 1 };
                low = pivotIndex + 1;
            }
        }
    }
    delete[] stack; 
}

void quick_sort_time(int arr[], int n, long double &time)
{
    clock_t start = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}

int find_median_comp(int arr[], int low, int high, long long &count_comp) {
    int mid = low + (high - low) / 2;

    if (++count_comp && arr[mid] < arr[low])
        swap(arr[mid], arr[low]);
    if (++count_comp && arr[high] < arr[low])
        swap(arr[high], arr[low]);
    if (++count_comp && arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    return arr[high];
}

int partition_comp(int arr[], int low, int high, long long &count_comp) {
    int pivot = find_median_comp(arr, low, high, count_comp);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (++count_comp && arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    count_comp += (high - low) + 1;

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort_comp_run(int arr[], int low, int high, long long &count_comp) {
    StackElement* stack = new StackElement[high - low + 1];
    int top = -1;

    stack[++top] = { low, high };

    while (++count_comp && top >= 0) {
        high = stack[top].end;
        low = stack[top--].start;

        while (++count_comp && low < high) {
            int pivotIndex = partition_comp(arr, low, high, count_comp);

            if (++count_comp && (pivotIndex - low < high - pivotIndex)) {
                stack[++top] = { pivotIndex + 1, high };
                high = pivotIndex - 1;
            } else {
                stack[++top] = { low, pivotIndex - 1 };
                low = pivotIndex + 1;
            }
        }
    }
    delete[] stack; 
}

void quick_sort_comp(int arr[], int n, long long &count_comp)
{
    quick_sort_comp_run(arr, 0, n - 1, count_comp);
}








