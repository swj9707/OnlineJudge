#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        int X; cin >> X;
        pq.push(X);
    }
    int answer = 0;
    while(pq.size() != 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        answer += first + second;
        pq.push(first + second);
    }
    cout << answer << '\n';
}