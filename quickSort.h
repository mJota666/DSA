#include <time.h>
#include <iostream>

using namespace std;


int find_median(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void quick_sort_time(int arr[], int n, long double &time);

int find_median_comp(int arr[], int low, int high, long long &count_comp);
int partition_comp(int arr[], int low, int high, long long &count_comp);
void quick_sort_comp_run(int arr[], int low, int high, long long &count_comp);
void quick_sort_comp(int arr[], int n, long long &count_comp);
