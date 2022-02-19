#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    long long answer = 987654321;
    vector<long long> vec(N*2);
    for(int i = 0; i < N*2; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < (N*2) / 2; i++){
        answer = min(answer, vec[i] + vec[(N*2) - 1 - i]);
    }
    cout << answer << '\n';
}