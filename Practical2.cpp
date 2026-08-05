#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(const vector<int>& arr, int key, int &comparisons)
{
    comparisons = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        comparisons++;
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search Function
int binarySearch(const vector<int>& arr, int key, int &comparisons)
{
    comparisons = 0;

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        comparisons++;

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    // Creating a sorted array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int index;
    int comparisons;

    // Linear Search Timing
    auto start = high_resolution_clock::now();
    index = linearSearch(arr, key, comparisons);
    auto stop = high_resolution_clock::now();

    cout << "\n===== Linear Search =====\n";
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found\n";

    cout << "Comparisons : " << comparisons << endl;
    cout << "Time Taken  : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Binary Search Timing
    start = high_resolution_clock::now();
    index = binarySearch(arr, key, comparisons);
    stop = high_resolution_clock::now();

    cout << "\n===== Binary Search =====\n";
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found\n";

    cout << "Comparisons : " << comparisons << endl;
    cout << "Time Taken  : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
