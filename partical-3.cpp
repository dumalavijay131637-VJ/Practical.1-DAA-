#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

//--------------- MAX HEAP ----------------//

void adjustMaxHeap(vector<int> &data, int size, int root)
{
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && data[leftChild] > data[largest])
        largest = leftChild;

    if (rightChild < size && data[rightChild] > data[largest])
        largest = rightChild;

    if (largest != root)
    {
        swap(data[root], data[largest]);
        adjustMaxHeap(data, size, largest);
    }
}

void buildMaxHeap(vector<int> &data)
{
    for (int i = data.size() / 2 - 1; i >= 0; i--)
        adjustMaxHeap(data, data.size(), i);
}

void heapSortMax(vector<int> &data)
{
    buildMaxHeap(data);

    for (int i = data.size() - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        adjustMaxHeap(data, i, 0);
    }
}

//--------------- MIN HEAP ----------------//

void adjustMinHeap(vector<int> &data, int size, int root)
{
    int smallest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && data[leftChild] < data[smallest])
        smallest = leftChild;

    if (rightChild < size && data[rightChild] < data[smallest])
        smallest = rightChild;

    if (smallest != root)
    {
        swap(data[root], data[smallest]);
        adjustMinHeap(data, size, smallest);
    }
}

void buildMinHeap(vector<int> &data)
{
    for (int i = data.size() / 2 - 1; i >= 0; i--)
        adjustMinHeap(data, data.size(), i);
}

void heapSortMin(vector<int> &data)
{
    buildMinHeap(data);

    for (int i = data.size() - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        adjustMinHeap(data, i, 0);
    }

    reverse(data.begin(), data.end());
}

//--------------- MAIN ----------------//

int main()
{
    int size;

    cout << "Enter number of elements: ";
    cin >> size;

    srand((unsigned)time(NULL));

    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
        numbers[i] = rand() % 100000;

    vector<int> maxHeapData = numbers;
    vector<int> minHeapData = numbers;

    auto start = high_resolution_clock::now();
    heapSortMax(maxHeapData);
    auto finish = high_resolution_clock::now();

    auto maxNano = duration_cast<nanoseconds>(finish - start);
    auto maxMicro = duration_cast<microseconds>(finish - start);

    start = high_resolution_clock::now();
    heapSortMin(minHeapData);
    finish = high_resolution_clock::now();

    auto minNano = duration_cast<nanoseconds>(finish - start);
    auto minMicro = duration_cast<microseconds>(finish - start);

    cout << "\n------ Max Heap Sort ------\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";

    cout << "\n------ Min Heap Sort ------\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";

    return 0;
}
