/*Write a program to use divide and conquer method to determine the time required to find
the maximum and minimum element in a list of n elements. The data for the list can be
generated randomly. Compare this time with the time taken by straight forward
algorithm or brute force algorithm for finding the maximum and minimum element for
the same list of n elements. Show the comparison by plotting a required graph for this
problem.*/

#include <stdio.h>
#include <time.h>
int max, min;
int a[100];
void maxmin(int i, int j) //DIVIDE AND CONQUER RULE
{
    int cnt = 0;
    cnt++;
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

void minMax(int A[], int n) //BRUTE FORCE ALGORITHM
{
    int count = 0;
    count++;
    int max = A[0];
    int min = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
        else if (A[i] < min)
            min = A[i];
    }
    int res[2] = {max, min};
}

int main()
{
    clock_t t;
    clock_t t1;
    int i, num, cnt, count;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);
    printf("Enter the numbers : \n");
    for (i = 1; i <= num; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    t = clock();
    maxmin(1, num);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nTime frequency is %lf", time_taken);
    t1 = clock();
    minMax(a, num);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
    printf("\nTime frequency is %lf", time_taken1);

    printf("\nMinimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}