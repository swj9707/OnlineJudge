#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K; cin >> N >> K;
    vector<int> arr(N);
    vector<int> visit(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int count = 1;
    int next = arr[0];
    while(true){
        if(visit[next] == 1){
            cout << "-1\n";
            break;
        }
        if(next == K){
            cout << count << '\n';
            break;
        }
        visit[next]++;
        next = arr[next];
        count++;
    }
    
}