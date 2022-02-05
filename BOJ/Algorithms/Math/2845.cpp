#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, P;
    cin >> L >> P;
    int value = L * P;
    for(int i = 0; i < 5; i++){
        int input;
        cin >> input;
        cout << input - value << '\n';
    }
}