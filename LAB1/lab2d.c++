
/*4.Write a program that takes three variable (a, b, c) as separate parameters and rotates the
values stored so that value a goes to be, b, b to c and c to a by using SWAP(x,y)
function that swaps/exchanges the numbers x & y.*/
#include <iostream>
using namespace std;

void SWAP(int &x, int &y, int &z)
{
    x = x + y + z;
    y = x - (y + z);
    z = x - (y + z);
    x = x - (y + z);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Initially a = " << a << ", b = "
         << b << ", c = " << c << endl;

    SWAP(a, b, c);

    cout << "After swapping a = " << a << ", b = "
         << b << ", c = " << c << endl;

    return 0;
}