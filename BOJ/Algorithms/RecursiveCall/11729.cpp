#include <iostream>

using namespace std;

void Hanoi(int N, int a, int b, int c){
    if(N == 1) cout << a << " " << c << '\n';
    else{
        Hanoi(N-1, a, c, b);
        cout << a << " " << c << '\n';
        Hanoi(N-1, b, a, c);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int sum = 1;
    for(int i = 0; i < N-1; i++) sum = sum*2 + 1;
    cout << sum << '\n';
    Hanoi(N, 1, 2, 3);
}