/*8.Write a program to display an array of n integers (n>1), where at every index of the
array should contain the product of all elements in the array except the element at the
given index. Solve this problem by taking single loop and without an additional array.
Input Array : 3 4 5 1 2
Output Array :40 30 24 120 6*/
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{

    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= arr[i];
    for (int i = 0; i < n; i++)
    {
        cout << (int)(prod * pow(arr[i], -1)) << ' ';
    }
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}