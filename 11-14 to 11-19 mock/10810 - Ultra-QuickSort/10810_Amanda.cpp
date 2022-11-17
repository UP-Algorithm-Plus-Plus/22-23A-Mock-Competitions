/*
*OnlineJudge
*10810 - Ultra-QuickSort
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

long long op = 0;

void merge (int array[], int begin, int mid, int end)
{ // copied from geeksforgeeks
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = array[begin + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
  
    // Merge the temp arrays back 
    // into arr[l..r]
    // Initial index of first subarray
    i = 0; 
  
    // Initial index of second subarray
    j = 0; 
  
    // Initial index of merged subarray
    k = begin; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            op += (n1 - i);
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements 
    // of L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort (int array[], int begin, int end)
{
    if (begin >= end)
        return;
    
    int mid = begin + (end-begin)/2;
    mergesort (array, begin, mid);
    mergesort (array, mid+1, end);
    merge (array, begin, mid, end);
}
int main ()
{
    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
        
        int array[N];
        for (int n = 0; n < N; n++)
            cin >> array[n];

        op = 0;
        mergesort(array, 0, N - 1);

        cout << op << endl;
    }
    return 0;
}