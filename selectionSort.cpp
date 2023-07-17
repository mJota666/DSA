#include "header.h"

//https://www.geeksforgeeks.org/selection-sort/
void selection_sort_comp(int *a, int n, int &count_comp){
    count_comp = 0; 
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; ++ count_comp && i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; ++ count_comp && j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

void selection_sort_time(int *a, int n, long double &time){
    time = 0; 
    clock_t start, end;
    start = clock();
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0;  i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1;  j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
    end = clock() ;
    setprecision(5);
    time = (double)(end - start) / CLOCKS_PER_SEC;
}


