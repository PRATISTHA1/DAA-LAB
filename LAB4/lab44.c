/*Write a program that uses a divide-and-conquer algorithm/user defined function for the
exponentiation problem of computing an where a > 0 and n is a positive integer. How
does this algorithm compare with the brute-force algorithm in terms of number of
multiplications made by both algorithms.*/

#include <stdio.h>
#include <time.h>
int power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

double powere(double x, unsigned int n)
{
    double product = 1;
    for (int i = 0; i < n; i++)
    {
        product = product * x;
    }
    return product;
}

int main()
{
    clock_t t;
    clock_t t1;
    int x;
    printf("Enter the number");
    scanf("%d", &x);
    unsigned int y;
    printf("Enter the number");
    scanf("%d", &y);
    t = clock();
    printf("%d", power(x, y));
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nTime frequency is %lf", time_taken);
    printf("\n");
    t1 = clock();
    printf("%f", powere(x, y));
    t1 = clock() - t1;
    double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
    printf("\nTime frequency is %lf", time_taken1);
    return 0;
}