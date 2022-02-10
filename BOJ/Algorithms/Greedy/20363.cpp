#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int X, Y;
    int answer;
    cin >> X >> Y;
    if (X >= Y) answer = (X + Y) + Y / 10;
    else answer = (X + Y) + X / 10;
    cout << answer << '\n';
}