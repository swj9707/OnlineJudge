#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    float answer = 0;
    vector<float> maxScore(N+1);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            int participant;
            float score;
            cin >> participant >> score;
            maxScore[participant] = max(maxScore[participant], score);
        }
    }
    sort(maxScore.begin(), maxScore.end(), greater<float>());
    for(int i = 0; i < K; i++){
        answer += maxScore[i];
    }
    cout << fixed;
    cout.precision(1);
    cout << answer << '\n';
}