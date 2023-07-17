#include <time.h>
#include <iostream>
using namespace std;

int partition_comp(int arr[], int low, int high, unsigned long long &count_comp);
void quick_sort_comp_run(int arr[], int low, int high, unsigned long long &count_comp);
void quick_sort_comp(int arr[], int n, unsigned long long &count_comp);

int partition_time(int arr[], int low, int high);
void quick_sort_time_run(int arr[], int low, int high);
void quick_sort_time(int arr[], int n, long double &time);