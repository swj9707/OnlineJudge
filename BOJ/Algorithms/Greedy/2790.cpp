#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int answer = 1;
    vector<int> racer(N);
    for(int i = 0; i < N; i++){
        cin >> racer[i];
    }
    sort(racer.begin(), racer.end(), greater<int>());
    int score = racer[0] + 1;
    for(int i = 1; i < N; i++){
        if(racer[i] + N >= score){
            answer++;
        }
        score = max(score. racer[i] + i  + 1);
    }
    cout << answer << '\n';
    
}