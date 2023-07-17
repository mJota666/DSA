#include "header.h"
/*
 https://www.youtube.com/watch?v=FgExRtl66Lc
 */

void shaker_sort_comp(int *a, int n, int &count_comp)
{
    int left = 0 ;
    int right, mark ;
    // mark được dùng để đánh dấu chuỗi đã được duyệt qua và có thứ tự rồi.
    right = mark = n-1;
    
    while ( ++count_comp && left < right)
    {
        for (int i = right ; i > left ; i--)
        {
            if ( ++count_comp  &&a[i] < a[i-1])
            {
                swap(a[i], a[i-1]);
                mark = i;
            }
        }
        count_comp += (right - left + 1);
        left = mark;
        
        for (int j = left; j > right ; j++)
        {
            if (++count_comp  && a[j] < a[j+1])
            {
                swap(a[j], a[j+1]);
                mark = j;
            }
        }
        count_comp += (right - left + 1);
        right  = mark;
        
    }
}
void shaker_sort_time(int *a, int n, long double &time)
{
    time = 0;
    clock_t start, end;
    start = clock();
    int left = 0 ;
    int right, mark ;
    // mark được dùng để đánh dấu chuỗi đã được duyệt qua và có thứ tự rồi.
    right = mark = n-1;
    
    while ( left < right)
    {
        for (int i = right ; i > left ; i--)
        {
            if (  a[i] < a[i-1])
            {
                swap(a[i], a[i-1]);
                mark = i;
            }
        }
        left = mark;
        
        for (int j = left; j < right ; j++)
        {
            if ( a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                mark = j;
            }
        }
        right  = mark;
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
