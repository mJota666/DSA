#include <time.h>
#include <iostream>
#include <cstring>
using namespace std;

int max_value_comp(int *arr, int n, long long &count_comp);
void counting_sort_comp(int *arr, int capacity, long long &count_comp);
int max_value(int *arr, int n);
void counting_sort_time(int *arr, int capacity, long double &time);