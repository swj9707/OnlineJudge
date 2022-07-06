#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    long long numerator = 1, denumerator = 1;
    long long answer;
    for(int i = N; i >= N - M; i--){
        numerator *= i;
    }
    for(int i = 1; i <= N; i++){
        denumerator *= 1;
    }
    answer = numerator / denumerator;
    cout << answer << '\n';
    return 0;
}