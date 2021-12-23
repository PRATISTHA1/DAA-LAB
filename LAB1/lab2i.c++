/*9.Write a program using a function for computing ⌊√n⌋ for any positive integer. Besides
assignment and comparison, your algorithm may only use the four basic arithmetic
operations.*/
#include <stdio.h>

int main()
{
    int number;

    float temp, sqrt;

    printf("Provide the number: \n");

    scanf("%d", &number);

    sqrt = number / 2;
    temp = 0;

    while (sqrt != temp)
    {

        temp = sqrt;

        sqrt = (number / temp + temp) / 2;
    }

    printf("The square root of '%d' is '%f'", number, sqrt);
    return 0;
}