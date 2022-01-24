#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int A1, B1, A2, B2;
    cin >> A1 >> B1;
    cin >> A2 >> B2;
    int C1, C2;
    C2 = B1 * B2;
    C1 = A1 * B2 + A2 * B1;
    int gcdValue = gcd(C1, C2);
    C1 /= gcdValue;
    C2 /= gcdValue;
    cout << C1 << " " << C2 << '\n';
}