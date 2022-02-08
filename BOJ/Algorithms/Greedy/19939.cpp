#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> vec(K);
    int sum = 0;
    for(int i = 1; i <= K; i++) sum += i;
    N -= sum;
    if(N < 0){
        cout << "-1\n";
    }
    else{
        if(N % K == 0) cout << K -1 << '\n';
        else if(N % K != 0) cout << K << '\n';
    }
}