/*Write a program by using an user defined function for computing ⌈ √n⌈ for any
positive integer n. Besides assignment and comparison, your algorithm may only use the
four basic arithmetical operations.
*/
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