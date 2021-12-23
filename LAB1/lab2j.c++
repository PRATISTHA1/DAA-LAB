/*10.Assume that you are given a rudimentary programming language which contains only
four operators, viz., +, −, abs and div. + and − have their usual meanings, while div(a, b)
returns the quotient of a/b and abs(a) returns the absolute value of a. Write a program to
solve this problem by using a function max(a, b) that takes two integers a and b as input
and returns the maximum of the two. Note that you can only use the operators provided;
in particular, the constructs ”if”, “while”, or “for” are not available.*/

#include <bits/stdc++.h>
using namespace std;

int maximum(int x, int y)
{
    return ((x + y + abs(x - y)) / 2);
}

int main()
{
    int x = 99, y = 18;

    cout << "Maximum  number is : " << maximum(x, y) << endl;
}
