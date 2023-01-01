#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, N;
    int answer = 0;
    cin >> P >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < N; i++){
        if (P < 200){
            P += vec[i];
            answer++;
        } else {
            break;
        }
    }

    cout << answer + 1 << '\n';
}