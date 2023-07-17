#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int count_comp = 0; // Counter for comparisons

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        count_comp++; // Increment comparison counter
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    count_comp += (high - low) + 1;

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(vector<int>& arr, int low, int high) {
    if (++count_comp && low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    // Generate an array from 1 to 500,000
    vector<int> arr(500000);
    for (int i = 0; i < 500000; i++) {
        arr[i] = i + 1;
    }

    // Shuffle the array randomly
    // random_device rd;
    // mt19937 g(rd());
    // shuffle(arr.begin(), arr.end(), g);

    // Sort the array using quicksort
    quicksort(arr, 0, arr.size() - 1);

    // Print the sorted array
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    
    cout << "\nNumber of comparisons: " << count_comp << endl; // Print the number of comparisons
    
    return 0;
}
