#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

void countingSort(vector<int>& arr);
void printArray(vector<int>& arr, int n);


int main()
{
    int size = 1000000;
    vector<int> vec(size);
    //int arr[size];
    for(int i = 0; i<size; i++){
      vec[i] = rand()%size;

    }


    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    countingSort(vec);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
     //printArray(vec, size);

    return 0;
}

void countingSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}


void printArray(vector<int>& arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
