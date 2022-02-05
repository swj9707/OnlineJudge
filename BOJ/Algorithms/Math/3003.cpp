#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Arr[6] = {1, 1, 2, 2, 2, 8};
    int input[6];
    for(int i = 0; i < 6; i++){
        cin >> input[i];
    }
    for(int i = 0; i < 6; i++){
        cout << Arr[i] - input[i] << '\n';
    }
}