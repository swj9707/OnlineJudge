#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int X;
    cin >> X;
    int sum = 0;
    while(X > 0){
        if( X % 2 == 1){
            sum++;
        }
        X /= 2;
    }
    cout << sum << '\n';
}