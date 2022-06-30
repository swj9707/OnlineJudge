#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    int answer = 0;
    unordered_map<string, int> uom;
    
    while(N--){
        string tmp; cin >> tmp;
        uom[tmp] = 1;
    }
    while(M--){
        string tmp; cin >> tmp;
        if(uom[tmp] == 1){
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}