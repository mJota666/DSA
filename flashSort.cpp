#include "flashSort.h"

using namespace std;

/*
https://www.youtube.com/watch?v=CAaDJJUszvE
*/

void flash_sort(int arr[], int n)
{
    // Number of buckets
    int m = 0.45 * n;

    // Calculate the size of the main bucket and create it
    int *L = new int[m + 1];

    // Find min, max
    int minValue, maxValue;
    minValue = maxValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
            minValue = arr[i];
        else if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    // Initialize the L bucket with zeros
    for (int j = 0; j <= m; j++)
        L[j] = 0;

    // Count the elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int k = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        L[k]++;
    }

    // Calculate the starting position of each bucket (index)
    for (int j = 1; j < m; j++)
        L[j] = L[j] + L[j - 1];

    // Perform the flash sort
    int i = 0;
    int j = m - 1;
    int numMoves = 0; // Tracks the number of moves made during sorting
    while (numMoves < n)
    {
        while (i > L[j] - 1)
        {
            i++;
            j = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        }

        int flash = arr[i];
        while (i != L[j])
        {
            j = static_cast<int>(static_cast<double>(m - 1) * (flash - minValue) / (maxValue - minValue));
            int temp = arr[L[j] - 1];
            arr[L[j] - 1] = flash;
            flash = temp;
            L[j]--;
            numMoves++;
        }
    }

    // Perform insertion sort on each bucket
    for (int k = 1; k < m; k++)
    {
        for (int i = L[k] - 2; i >= L[k - 1]; i--)
        {
            int temp = arr[i];
            int j = i + 1;
            while (temp > arr[j])
            {
                arr[j - 1] = arr[j];
                j++;
            }
            arr[j - 1] = temp;
        }
    }

    delete[] L;
}

void flash_sort_comp(int arr[], int n, long long &count_comp)
{
    count_comp = 0;

    // Number of buckets
    int m = 0.45 * n;

    // Calculate the size of the main bucket and create it
    int *L = new int[m + 1];

    // Find min, max
    int minValue, maxValue;
    minValue = maxValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (++count_comp && arr[i] < minValue)
            minValue = arr[i];
        else if (++count_comp && arr[i] > maxValue)
            maxValue = arr[i];
    }
    count_comp += n;
    // Initialize the L bucket with zeros
    for (int j = 0; j <= m; j++)
        L[j] = 0;
    count_comp += (m + 2);
    // Count the elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int k = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        L[k]++;
    }
    count_comp += (n + 1);
    // Calculate the starting position of each bucket (index)
    for (int j = 1; j < m; j++)
        L[j] = L[j] + L[j - 1];
    count_comp += (m);

    // Perform the flash sort
    int i = 0;
    int j = m - 1;
    int numMoves = 0; // Tracks the number of moves made during sorting
    while (++count_comp && numMoves < n)
    {
        while (++count_comp && i > L[j] - 1)
        {
            i++;
            j = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        }

        int flash = arr[i];
        while (++count_comp && i != L[j])
        {
            j = static_cast<int>(static_cast<double>(m - 1) * (flash - minValue) / (maxValue - minValue));
            int temp = arr[L[j] - 1];
            arr[L[j] - 1] = flash;
            flash = temp;
            L[j]--;
            numMoves++;
        }
    }

    // Perform insertion sort on each bucket
    for (int k = 1; ++count_comp, k < m; k++)
    {
        for (int i = L[k] - 2; ++count_comp, i >= L[k - 1]; i--)
        {
            int temp = arr[i];
            int j = i + 1;
            while (++count_comp && temp > arr[j])
            {
                arr[j - 1] = arr[j];
                j++;
            }
            arr[j - 1] = temp;
        }
    }

    delete[] L;
}

void flash_sort_time(int arr[], int n, long double &time)
{
    clock_t start, end;

    start = clock();

    // Number of buckets
    int m = 0.45 * n;

    // Calculate the size of the main bucket and create it
    int *L = new int[m + 1];

    // Find min, max
    int minValue, maxValue;
    minValue = maxValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
            minValue = arr[i];
        else if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    // Initialize the L bucket with zeros
    for (int j = 0; j <= m; j++)
        L[j] = 0;

    // Count the elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int k = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        L[k]++;
    }

    // Calculate the starting position of each bucket (index)
    for (int j = 1; j < m; j++)
        L[j] = L[j] + L[j - 1];

    // Perform the flash sort
    int i = 0;
    int j = m - 1;
    int numMoves = 0; // Tracks the number of moves made during sorting
    while (numMoves < n)
    {
        while (i > L[j] - 1)
        {
            i++;
            j = static_cast<int>(static_cast<double>(m - 1) * (arr[i] - minValue) / (maxValue - minValue));
        }

        int flash = arr[i];
        while (i != L[j])
        {
            j = static_cast<int>(static_cast<double>(m - 1) * (flash - minValue) / (maxValue - minValue));
            int temp = arr[L[j] - 1];
            arr[L[j] - 1] = flash;
            flash = temp;
            L[j]--;
            numMoves++;
        }
    }

    // Perform insertion sort on each bucket
    for (int k = 1; k < m; k++)
    {
        for (int i = L[k] - 2; i >= L[k - 1]; i--)
        {
            int temp = arr[i];
            int j = i + 1;
            while (temp > arr[j])
            {
                arr[j - 1] = arr[j];
                j++;
            }
            arr[j - 1] = temp;
        }
    }

    delete[] L;
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
