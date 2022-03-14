#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int sum = 0;
    while(true){
        cin >> N;
        if(N == -1) break;
        sum += N;
    }
    cout << sum << '\n';
}