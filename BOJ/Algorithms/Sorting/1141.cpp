#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int answer = 0;
    vector<string> vec(N);
    vector<bool> check(N, true);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(vec[j].substr(0, vec[i].size()) == vec[i]){
                check[i] = false;
                break;
            }
        }
    }

    for(auto i : check){
        if(i) answer++;
    }

    cout << answer << '\n';
}