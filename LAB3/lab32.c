/*3.2 Let A be a list of n (not necessarily distinct) integers. Write a program by using User
Defined Function(UDF)s to test whether any item occurs more than ⌈ n/2⌈ times in A.
a) UDF should take O(n2

) time and use no additional space.
b) UDF should take O(n) time and use O(1) additional space.*/
#include <stdio.h>
#include <math.h>

void findnum(int arr[], int n)
{
    int max_count = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > max_count)
        {
            max_count = count;
            index = i;
        }
    }
    if (max_count > n / 2)
        printf("o(n^2) yes, element is present");
    else
        printf("o(n^2) no, element is present");
}

int find_n(int A[], int n)
{
    int m;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
        {
            m = A[j], i = 1;
        }
        else
        {
            (m == A[j]) ? i++ : i--;
        }
    }
    return m;
}

int main()
{
    int arr[100], np;
    printf("Enter the size\n");
    scanf("%d", &np);
    printf("Enter the array\n");
    for (int i = 0; i < np; i++)
        scanf("%d", &arr[i]);

    findnum(arr, np);
    if (find_n(arr, np) != arr[np - 1])
        printf("\n o(n) yes,element present");
    else
        printf("\n o(n) no element present");

    return 0;
}