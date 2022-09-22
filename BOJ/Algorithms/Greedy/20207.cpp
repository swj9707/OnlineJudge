#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int answer = 0;
    vector<pair<int, int>> scheduleData(N);
    int maxIdx = 0;
    vector<int> vec(367);
    for(int i = 0; i < N ; i++){
        cin >> scheduleData[i].first >> scheduleData[i].second;
        vec[scheduleData[i].first]++;
        vec[scheduleData[i].second+1]--;
    }
    int height = 0, width = 0;
    for(int i = 1; i < 367; i++){
        vec[i] += vec[i-1];
        if(vec[i] == 0){
            answer += height * width;
            height = 0;
            width = 0;
        } else {
            width++;
            height = max(height, vec[i]);
        }
    }
    
    cout << answer << '\n';
}