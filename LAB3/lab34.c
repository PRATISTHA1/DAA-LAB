/*
3.4 Let A be an array of n integers a0,a1,... ,an-1 (negative integers are allowed), denoted, by
A[i... j], the sub-array ai, ai+1,... ,aj for i≤j. Also let Si-j denote the sum ai + ai+1 +· · · + aj. Write a programby using an udf that must run in O(n2

) time to find out the maximum
value of Si-j for all the pair i, j with 0 ≤ i ≤ j ≤ n-1. Call this maximum value S. Also
obtains the maximum of these computed sums. Let j < i in the notation A[i... j] is also
allowed. In this case, A[i... j] denotes the empty sub-array (that is, a sub-array that ends
before it starts) with sum Si-j = 0. Indeed, if all the elements of A are negative, then one
returns 0 as the maximum sub-array sum.
a. For example, for the array A[]={1, 3, 7, 2, 1, 5, 1, 2, 4, 6, 3}.
b. This maximum sum is S = S3-8 = 2+( 1)+5+( 1)+( 2)+4 = 7.*/
#include <stdio.h>

int main()
{
    int size, m = 0, l = 0;

    printf("Type the length of the array\n");
    scanf("%d", &size);
    int array[size];
    printf("type the elements of the array\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    int largest = array[0];
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + array[j];
            if (sum > largest)
            {
                m = i;
                l = j;
                largest = sum;
            }
        }
    }

    printf("\n The largest contigous subarray is");
    for (int z = m; z <= l; z++)
    {
        printf(" %d ", array[z]);
    }
    printf("\n The sum is");
    printf(" %d", largest);
    return 0;
}