#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int j, N; cin >> j >> N;
        int count = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for(int i = 0; i < N; i++){
            int r, c; cin >> r >> c;
            pq.push(r * c);
        }

        while(!pq.empty()){
            j -= pq.top();
            pq.pop();
            count++;
            
            if(j <= 0){
                break;
            }
        }
        cout << count << '\n';
    }
}