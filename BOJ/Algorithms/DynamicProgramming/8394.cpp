#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a =1, b = 0;
    int N;
    cin >> N;
    for(int i =0; i < N; i++){
        a = (a + b) % 10;
        b = a % 10;
    }
    cout << a << '\n';
}