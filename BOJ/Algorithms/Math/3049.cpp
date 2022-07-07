#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int answer = N * (N-1) * (N - 2) * (N-3) / 24;
    cout << answer << '\n';
}