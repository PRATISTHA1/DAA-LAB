/*Consider an n × n matrix A = (aij), each of whose elements aij is a nonnegative real
number, and suppose that each row and column of A sums to an integer value. We wish
to replace each element aij with either ⌈ aij⌈ or ⌈ aij⌈ without disturbing the row and
column sums.

Write a program by defining an user defined function that is used to produce the rounded matrix
as described in the above example. Find out the time complexity of your algorithm/function.*/

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the edge of the matrix (n x n): ");
    scanf("%d", &n);
    float arr[n][n];
    int int_array[n][n];
    // int column_sum[10] = { 0 }, row_sum[10] = { 0 };
    float column_sum[10] = {0}, row_sum[10] = {0};
    printf("Enter the elements (%d x %d) inlcuding float numbers: \n", n, n);
    //calculate the sum of every row and column + input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &arr[i][j]);
            row_sum[i] += arr[i][j] - ((int)(arr[i][j]));
            column_sum[j] += arr[i][j] - ((int)(arr[i][j]));
            int_array[i][j] = (int)arr[i][j];
        }
    }
    printf("\n\n\n");
    //0.000001 because apparently c float can't store 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row_sum[i] > 0.000001 && column_sum[j] > 0.000001)
            {
                int_array[i][j] += 1;
                row_sum[i]--;
                column_sum[j]--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", int_array[i][j]);
        }
        printf("\n");
    }
    return 0;
}