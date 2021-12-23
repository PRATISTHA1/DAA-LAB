/*5.Let A be n*n square matrix array. WAP by using appropriate user defined functions for
the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/

#include <iostream>
using namespace std;

int nz_elements(int arr[50][50], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
                c++;
        }
    }
    return c;
}
int major_sum(int arr[50][50], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            c += arr[i][j];
        }
    }
    return c;
}
void minor_diagnal(int arr[50][50], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf("\t");
        }
        for (int j = n - 1 - i; j < n; j++)
        {
            cout << "\t" << arr[i][j];
        }
        cout << "\n";
    }
}
int product_diagnal(int arr[50][50], int n)
{
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        c *= arr[i][i] * arr[i][n - 1 - i];
    }
    return c;
}
int main()
{
    int arr[50][50];
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "enter element : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> arr[i][j];
        }
    }
    cout << "Number of non zero elements=" << nz_elements(arr, n) << endl;
    cout << "Sum of elements above major diagnal=" << major_sum(arr, n) << endl;
    cout << "Elements below minor diagnal" << endl;
    minor_diagnal(arr, n);
    cout << "Product of diagnal elements=" << product_diagnal(arr, n) << endl;
}