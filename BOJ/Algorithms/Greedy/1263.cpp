#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<pair<int, int>> vec(N+1);
    for(int i = 1; i <= N; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), compare);
    
    for(int i = 0; i < N; i++){
        int minimumStartTime = vec[i].second - vec[i].first;
        if(minimumStartTime < vec[i+1].second){
            vec[i+1].second = minimumStartTime;
        }
    }
    vec[N].second = vec[N-1].second - vec[N-1].first;
    if(vec[N].second < 0) {
        cout << "-1\n";
    } else {
        cout << vec[N].second <<'\n';
    }
}