/*

*/

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int lower, int upper)
{
    int pivot = lower;
    int i = lower;
    int j = upper;

    while (i < j)
    {
        while (A[i] <= A[pivot])
        {
            i++;
        }
        while (A[j] >= A[pivot])
        {
            j--;
        }
        if (i < j)
        {
            // swap
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    if (pivot != j)
    {
        // swap
        int temp = A[pivot];
        A[pivot] = A[j];
        A[j] = temp;
    }
    return j;
}

void quick_sort(int A[], int lower, int upper)
{
    if (lower < upper)
    {
        int location = partition(A, lower, upper);
        quick_sort(A, lower, location - 1);
        quick_sort(A, location + 1, upper);
    }
}

int main(void)
{
    // clock_t time;

    int n, lower, upper;
    cout << "\n Enter the number of elements needed in the array : ";
    cin >> n;
    int *A = new int[n];

    lower = 0;
    upper = n;
    // cout << "\n Enter the initial array of numbers : ";
    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    cout << endl;

    // finding the clock cycles
    auto start = std::chrono::high_resolution_clock::now();
    // to sort
    quick_sort(A, lower, upper);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    cout << " The final array of numbers : ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    long long microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    cout << "\n Processor time taken : " << microseconds << " seconds" << endl;

    // to check the sorted array

    cout << "\n Enter the number of elements needed in the array : ";
    cin >> n;

    lower = 0;
    upper = n;
    cout << "\n Enter the initial array of numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << endl;

    // finding the clock cycles
    start = std::chrono::high_resolution_clock::now();
    // to sort
    quick_sort(A, lower, upper);

    elapsed = std::chrono::high_resolution_clock::now() - start;

    cout << " The final array of numbers : ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    cout << "\n Processor time taken : " << microseconds << " seconds" << endl;

    cout << endl;
    return 0;
}