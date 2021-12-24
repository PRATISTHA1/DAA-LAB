/*4.2 Write a program to sort a list of n elements using the merge sort method and determine
the time required to sort the elements. Repeat the experiment for different values of n
and different nature of data (random data, sorted data, reversely sorted data) in the list.
n is the user input and n integers can be generated randomly. Finally plot a graph of the
time taken versus n.*/

#include <stdio.h>
#include <time.h>
int count = 0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1 + 1], R[n2 + 1];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + j + 1];
    }
    L[n1] = 99999;
    R[n2] = 99999;

    i = 0;
    j = 0;
    for (k = l; k < r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int m = l + (r - l) / 2;
        count++;
        mergeSort(arr, l, m);
        count++;
        mergeSort(arr, m + 1, r);
        count++;

        merge(arr, l, m, r);
        count++;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("\nValue of 'n' : %d\nEntered SORTED array is :\n", n);
    printArray(arr1, n);
    clock_t t_sorted = clock();
    mergeSort(arr1, 0, n - 1);
    t_sorted = clock() - t_sorted;
    double time_taken = (double)(t_sorted) / CLOCKS_PER_SEC;
    printf("Sorted array is :\n");
    printArray(arr1, n);
    printf("COUNT : %d\nTime taken : %f\n", count, time_taken);

    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    n = sizeof(arr2) / sizeof(arr2[0]);
    count = 0;
    printf("\nValue of 'n' : %d\nEntered REVERSELY SORTED array is :\n", n);
    printArray(arr2, n);
    clock_t t_reverse = clock();
    mergeSort(arr2, 0, n - 1);
    t_reverse = clock() - t_reverse;
    time_taken = (double)(t_reverse) / CLOCKS_PER_SEC;
    printf("Sorted array is :\n");
    printArray(arr2, n);
    printf("COUNT : %d\nTime taken : %f\n", count, time_taken);

    int arr3[] = {10, 5, 9, 3, 8, 1, 6, 2, 7, 4};
    n = sizeof(arr3) / sizeof(arr3[0]);
    count = 0;
    printf("\nValue of 'n' : %d\nEntered RANDOM array is :\n", n);
    printArray(arr3, n);
    clock_t t_random = clock();
    mergeSort(arr3, 0, n - 1);
    t_random = clock() - t_random;
    time_taken = (double)(t_random) / CLOCKS_PER_SEC;
    printf("Sorted array is :\n");
    printArray(arr3, n);
    printf("COUNT : %d\nTime taken : %f\n", count, time_taken);

    return 0;
}