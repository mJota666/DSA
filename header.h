#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
using namespace std;
void counting_sort_cmp(int *arr, int capacity, int &count_comp);
void counting_sort_time(int *arr, int capacity, double &time);


// command
void command_1(int argc, char* argv[]);
void command_2( int argc, char* argv[]);
void command_3(int argc, char *argv[]);
void command_4(int argc, char* argv[]);
void command_5(int argc, char* argv[]);
void output_file(int n);

//

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
// Đạt
/*
void quick_sort_comp(int arr[], int low, int high, int &count_comp);
void quick_sort_time(int arr[], int low, int high, long double &time);
*/
void selection_sort_comp(int *a, int n, int &count_comp);
void selection_sort_time(int *a, int n,long double &time);


void counting_sort_comp(int *arr, int capacity, int &count_comp);
void counting_sort_time(int *arr, int capacity, long double &time);

//Minh
void print_querry(string output_param, int count_comp,long double time_use);

void insertion_sort_comp(int a[], int n,int  &count_compare);
void insertion_sort_time(int a[], int n, long double &time_use);
void insertion_sort(int a[], int n);
/*
void merge_sort_comp(int a[], int leftIndex, int rightIndex, int &count_compare);
void merge_sort_time(int a[], int n, long  double &time_use);
*/

void shell_sort_time(int a[], int n, long double &time_use);
void shell_sort(int a[], int n);
void shell_sort_comp(int a[], int n, int &count_compare);

// Thành
void heap_sort_comp(int *a ,int n, int &count_comp);
void heap_sort_time(int *a ,int n,long double &time);
void bubble_sort_comp(int *a ,int n, int &count_comp);
void bubble_sort_time(int *a ,int n,long double &time);
void shaker_sort_comp(int *a, int n, int &count_comp);
void shaker_sort_time(int *a, int n, long double &time);

// Duy

void flash_sort_time(int arr[], int n, long double& time);
void flash_sort_comp(int a[], int n, int &comp);

void radix_sort_comp(int a[], int n, int &comp);
void radix_sort_time(int arr[], int n, long double& time);

#endif  // HEADER_H
