#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<long long> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long answer = 0;
    for(int i = 1; i < N; i++){
        answer += vec[i] * min(i, K);
    }
    cout << answer << '\n';
}