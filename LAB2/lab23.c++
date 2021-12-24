/*Write a menu driven program as given below, to sort an array of n integers in ascending
order by insertion sort algorithm and determine the time required (in terms of
step/frequency count) to sort the elements. Repeat the experiment for different values of
n and different nature of data (i.e.apply insertion sort algorithm on the data of array
that are already sorted, reversely sorted and random data). Finally plot a graph of the
time taken versus n for each type of data. The elements can be read from a file or can be
generated using the random number generator.*/

#include <iostream>
using namespace std;

void insert_ascending_sort(int data[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (i = 1; i < n; i++)
    {
        temp = data[i];
        for (j = i - 1; j >= 0 && temp < data[j]; j--)
        {
            data[j + 1] = data[j];
        }
        data[j + 1] = temp;
    }
}

void insert_descending_sort(int data[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (i = 1; i < n; i++)
    {
        temp = data[i];
        for (j = i - 1; j >= 0 && temp > data[j]; j--)
        {
            data[j + 1] = data[j];
        }
        data[j + 1] = temp;
    }
}

void print(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
int main()
{
    int num[] = {5, 3, 7, 4, 3, 9, 6, 2, 10, 4, 3, 7, 1};
    int len = sizeof(num) / sizeof(int);

    cout << "  before sort: ";
    print(num, len);

    insert_ascending_sort(num, len);
    cout << "after sort: ";
    print(num, len);

    insert_descending_sort(num, len);
    cout << "after desending sort: ";
    print(num, len);

    return 0;
}