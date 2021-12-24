/*
PRATISTHA SRIVASTAVA
1906621

3.1 Rewrite the program no-2.3 (Insertion Sort) with the following details.
i. Compare the best case, worst case and average case time complexity with the same
data except time complexity will count the CPU clock time.
ii. Plot a graph showing the above comparison (n, the input data Vs. CPU times for
best, worst & average case)
iii. Compare manually program no-2.1 graph vs program no-3.1 graph and draw your
inference.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double d;
int insertion(int arr[], int n)
{
    clock_t start = clock();
    int i, key, j, c1 = 0, c2 = 0;
    for (i = 1; i < n; i++)
    {
        c1++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            c2++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();
    d = (double)(end - start) / CLOCKS_PER_SEC;
    return c1 + c2;
}
void descending(int number[], int n)
{
    int i, j, a;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (number[i] < number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements:- ");
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
        ar[i] = rand();
    printf("\t\tStep Count\tClock Time\n");
    int a = insertion(ar, n);
    printf("Average:-\t  %d\t%f\n", a, d);
    a = insertion(ar, n);
    printf("Best:-\t\t  %d\t\t%f\n", a, d);
    descending(ar, n);
    a = insertion(ar, n);
    printf("Worst:-\t\t  %d\t%f\n", a, d);
    return 0;
}