#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = -1;
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = N - 1; i >= 2; i--){
        if(vec[i] < vec[i-1] + vec[i-2]){
            answer = vec[i] + vec[i-1] + vec[i-2];
            break;
        }
    }
    cout << answer << '\n';
}