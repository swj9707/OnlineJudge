#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int amount = M * K;
    vector<int> penNum(N);
    for(int i = 0; i < N; i++){
        cin >> penNum[i];  
    }
    sort(penNum.begin(), penNum.end(), greater<int>());
    int count = 0;
    int sum = 0;
    for(auto i : penNum){
        sum += i;
        count++;
        if(sum >= amount){
            cout << count << '\n';
            return 0;
        }
    }
    cout << "STRESS" <<'\n';
    return 0;
}