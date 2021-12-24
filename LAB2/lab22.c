/*2. Write a program to find out GCD (greatest common divisor) using the following three
algorithms.
a) Euclid’s algorithm
b) Consecutive integer checking algorithm.
c) Middle school procedure which makes use of common prime factors. For finding
list of primes implement sieve of Eratosthenes algorithm.
Write a program to find out which algorithm is faster for the following data. Estimate
how many times it will be faster than the other two by step/frequency count method in
each case.
i. Find GCD of two numbers when both are very large i.e.GCD(31415, 14142) by
applying each of the above algorithms.
ii. Find GCD of two numbers when one of them can be very large i.e.GCD(56,
32566) or GCD(34218, 56) by applying each of the above algorithms.
iii. Find GCD of two numbers when both are very small i.e.GCD(12,15) by applying
each of the above algorithms.
iv. Find GCD of two numbers when both are same i.e.GCD(31415, 31415) or
GCD(12, 12) by applying each of the above algorithms.*/

#include <stdio.h>

int count = 0;

int main()
{
    int m, n;
    printf("Enter two integer numbers: ");
    scanf("%d %d", &m, &n);

    /* Euclid’s algorithm-- >
     while (n > 0)
     {
         int r = m % n;
         m = n;
         n = r;
         count++;
     }
     printf("GCD = %d \n", m);*/

    /* Consecutive integer checking algorithm -->
     int gcd;
     for (int i = 1; count++, i <= m && i <= n; ++i)
     {
         if (m % i == 0 && n % i == 0)
             gcd = i,count++;
     }
     printf("G.C.D of %d and %d is %d", m, n, gcd);*/

    // Middle school procedure -->
    int mx = m > n ? m : n;
    int fac1[mx], fac2[mx];
    int prime[mx + 1];
    prime[1] = 1;
    for (int i = 2; count++, i <= mx; i++)
        prime[i] = i;
    for (int i = 4; count++, i <= mx; i += 2)
        prime[i] = 2;
    for (int i = 3; count++, i * i <= mx; i++)
    {
        if (prime[i] == i)
        {
            count++;
            for (int j = i * i; count++, j <= mx; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i, count++;
            }
        }
    }

    int cntrm = 0, cntrn = 0;
    while (m != 1)
    {
        fac1[cntrm++] = prime[m];
        m /= prime[m], count++;
    }
    while (n != 1)
    {
        fac2[cntrn++] = prime[n];
        n /= prime[n], count++;
    }

    int i = 0, j = 0, gcd = 1;
    while (i < cntrm && j < cntrn)
    {
        count += 2;
        if (fac1[i] == fac2[j])
        {
            gcd *= fac1[i];
            i++, j++;
        }
        else if (fac1[i] < fac2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("GCD : %d", gcd);

    printf("\n\nCOUNT : %d", count);

    return 0;
}