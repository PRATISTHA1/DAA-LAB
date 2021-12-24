//PRATISTHA SRIVASTAVA
//1906621

/*1. Write a program to test whether a number n, entered through keyboard is prime or
not by using different algorithms you know for atleast 10 inputs and note down the time
complexity by step/frequency count method for each algorithm & for each input.
Finally make a comparision of time complexities found for different inputs, plot an
appropriate graph & decide which algothm is faster.*/
#include <stdio.h>

int count = 0;
int prime_chk(int n)
{
    count++;
    static int i = 2;

    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n == i)
    {
        return 0;
    }

    if (n % i == 0)
    {
        return 1;
    }

    i++;

    return prime_chk(n);
}

int main()
{
    int n, flag = 0;
    printf("Enter the number to check prime:");
    scanf("%d", &n);

    /* Algo 1 -->
     for (int i = 2; count++, i <= n / 2; i++)
    {
      if (n % i == 0)
    {
      printf("Number %d is not prime!", n);
    flag = 1;
    count++;
     break;
     }
     }*/

    /* Algo 2 -->
     for (int i = 2; count++, i * i <= n; i++)
     {
         if (n % i == 0)
         {
             printf("Number %d is not prime!", n);
             flag = 1;
             count++;
             break;
         }
     }*/

    // Algo 3 -->
    flag = prime_chk(n);

    if (flag == 0)
    {
        printf("Number %d is prime!", n);
    }
    else
    {
        printf("Number %d is not prime!", n);
    }

    printf("\n\nCOUNT : %d", count);
    return 0;
}