#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int answer = 0;

void DFS(vector<int> & vec, int ans){
    if(vec.size() == 3){
        ans += vec[0] * vec[2];
        answer = max(answer, ans);
        return;
    }
    for(int i = 0; i < vec.size() - 2; i++){
        vector<int> tmp = vec;
        tmp.erase(tmp.begin() + i + 1);
        DFS(tmp, ans + (vec[i] * vec[i + 2]));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    DFS(vec, 0);
    cout << answer << '\n';
}