#include <iostream>

using namespace std;

int Fac(int N){
    if(N == 0) return 1;
    int Answer = 1;
    for(int i = N; i >= 1; i--){
        Answer *= i;
    }
    return Answer;
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << Fac(N) / (Fac(K) * Fac(N-K));
}