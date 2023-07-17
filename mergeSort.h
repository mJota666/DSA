#include <cstring>
#include <time.h>

void merge(int a[], int leftIndex, int midIndex, int rightIndex);
void merge_sort(int a[], int leftIndex, int rightIndex);
void merge_comp_run(int a[], int leftIndex, int midIndex, int rightIndex, int &count_comp);
void merge_sort_comp_run(int a[], int leftIndex, int rightIndex, int &count_comp);

void merge_sort_comp(int a[], int n, int &count_comp);
void merge_sort_time(int a[], int n, long double &time_use);