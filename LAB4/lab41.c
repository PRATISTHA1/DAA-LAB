
/*PRATISTHA SRIVASTAVA
1906621

4.1 Write a program to search an element x in an array of n integers using binary search
algorithm that uses divide and conquer technique. Find out the best case, worst case and
average case time complexities for different values of n and plot a graph of the time
taken versus n. The n integers can be generated randomly and x can be choosen
randomly, or any element of the array or middle or last element of the array depending
on type of time complexity analysis.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int count = 0;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            count++;
            return mid;
        }
        if (arr[mid] > x)
        {
            count++;
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            count++;
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    count++;
    return -1;
}

int main()
{
    int *arr;
    clock_t t_best, t_avg, t_worst;
    int n, i;
    printf("\nEnter the Value of 'n' :");
    scanf("%d", &n);
    printf("\nEnter the Numbers in array :\n");
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            printf("\n");
        }
    }
    t_best = clock();
    int x = 5;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("%d is not present!\n", x) : printf("%d is present at position %d.\n", x, result + 1);
    t_best = clock() - t_best;
    double time_taken = ((double)t_best) / CLOCKS_PER_SEC;
    printf("Time taken in BEST CASE : %f seconds.\n", time_taken);
    printf("Count : %d\n\n", count);

    t_avg = clock();
    count = 0;
    x = 2;
    result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("%d is not present!\n", x) : printf("%d is present at position %d.\n", x, result + 1);
    t_avg = clock() - t_avg;
    time_taken = ((double)t_avg) / CLOCKS_PER_SEC;
    printf("Time taken in AVERAGE CASE : %f seconds.\n", time_taken);
    printf("Count : %d\n\n", count);

    t_worst = clock();
    count = 0;
    x = 0;
    result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("%d is not present!\n", x) : printf("%d is present at position %d.\n", x, result + 1);
    t_worst = clock() - t_worst;
    time_taken = ((double)t_worst) / CLOCKS_PER_SEC;
    printf("Time taken in WORST CASE : %f seconds.\n", time_taken);
    printf("Count : %d\n\n", count);

    return 0;
}