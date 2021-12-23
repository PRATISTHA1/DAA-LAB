/*6.Write a program to find out the second smallest and second largest element stored in an
array of n integers. n is the user input. The array takes input through random number
generation within a given range. How many different ways you can solve this problem.
Write your approaches & strategy for solving this problem.*/
#include <iostream>
using namespace std;
int main()
{
    int A[10], n, i, j, x;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter elements of array : ";
    for (i = 0; i < n; i++)
        cin >> A[i];
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] < A[j])
            {
                x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }
    cout << "Second largest number : " << A[1];
    cout << "\nSecond smallest number : " << A[n - 2];
    return 0;
}