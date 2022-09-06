#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> inputData(N);
    for(int i = 0; i < N; i++){
        cin >> inputData[i];
    }
    sort(inputData.begin(), inputData.end(), greater<int>());
    int answer = 0;
    for(int i = 0; i < K; i++){
        answer += inputData[i];
    }
    answer = answer - (K*(K-1)/2);
    cout << answer << '\n';
}