#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K; 
    cin >> N >> K;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());

    cout << vec[K-1] << '\n';
}