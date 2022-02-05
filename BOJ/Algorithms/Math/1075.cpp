#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, F;
    cin >> N >> F;
    int N_front = N / 100;
    int result;
    for(int i = 0; i < 100; i++){
        result = N_front * 100 + i;
        if(result % F == 0) break;
    }
    int N_rear = result % 100;
    if(N_rear / 10 == 0) cout<<"0"<<N_rear<<'\n';
    else cout << N_rear << '\n';
}