#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long answer = 0;
    cin >> N;
    vector<long long> growValue(N);
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        answer += tmp;
    }
    for(auto & i : growValue) cin >> i;
    sort(growValue.begin(), growValue.end());
    for(int i = 0; i < N; ++i){
        answer += growValue[i] * i;
    }
    cout << answer << '\n';
    return 0;
}