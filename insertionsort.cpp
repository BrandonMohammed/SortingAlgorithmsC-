
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void insertionSort(int [], int);
void printArray(int arr[], int n);

int main()
{
    int size = 5000;
    //vector<int> values(size);
    int arr[size];
    for(int i = 0; i<size; i++){
      arr[i] = rand()%size;

    }

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    insertionSort(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
     //printArray(arr, size);

    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
