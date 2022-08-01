#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

void bucketSort(float arr[], int n);
void printArray(float[], int n);


int main()
{
   int size = 1000000;

  /*   //vector<int> vec(size);
    float arr[size];
    for(int i = 0; i<size; i++){
      arr[i] = rand()%size;

    }*/

    float arr[size];
    srand((unsigned)time(NULL));
    for(int i = 0; i<size; i++){
      arr[i] = (float)rand()/RAND_MAX;

    }

    //int n = sizeof(arr) / sizeof(arr[0]);
    //bucketSort(arr, n);


    int n = sizeof(arr) / sizeof(arr[0]);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
  //  bucketSort(arr, size);
    bucketSort(arr, n);
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
void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
void printArray(float arr[], int n)
{

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
