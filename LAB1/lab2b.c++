/*2. Write a program to store random numbers into an array of n integers, where the array
must contains some duplicates. Do the following:
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.*/

#include <iostream>

using namespace std;

int main()
{
    int a[50], n, count = 0;
    cout << "\nEnter the number of elements :";
    cin >> n;
    cout << "\nInput the array elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max_count = 0;

    for (int i = 0; i < 5; i++)
    {
        int count = 1;
        for (int j = i + 1; j < 5; j++)
            if (a[i] == a[j])
                count++;
        if (count > max_count)
            max_count = count;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                break;
            }
        }
    }
    cout << "\nTotal number of duplicate elements found in array: " << count << endl;

    for (int i = 0; i < 5; i++)
    {
        int count = 1;
        for (int j = i + 1; j < 5; j++)
            if (a[i] == a[j])
                count++;
        if (count == max_count)
            cout << "Most frequent element in array : " << a[i] << endl;
    }
}