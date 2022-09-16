#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> books(N);
    for(int i = 0; i < N; i++){
        cin >> books[i];
    }
    int answer = 0;
    int count = 0;
    for(auto i : books){
        if(count + i > M){
            count = i;
            answer++;
        } else {
            count += i;
        }
    }
    if(count) answer++;
    cout << answer << '\n';
}