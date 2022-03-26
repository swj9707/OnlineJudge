#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    long long answer = 0;
    for(int i = 1; i <= N; i *= 10){
        answer += N - i + 1;
    }
    cout << answer << '\n';
}