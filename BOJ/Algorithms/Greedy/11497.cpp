#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        int N;
        cin >> N;
        vector<int> data(N);
        for(int i = 0; i < N; i++) cin >> data[i];
        sort(data.begin(), data.end());
        int result = 0;
        for(int i = 2; i < N; i++){
            int tmp = data[i] - data[i - 2];
            result = max(tmp, result);
        }
        cout << result << '\n';
    }
}