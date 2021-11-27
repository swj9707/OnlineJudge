#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    // 1 5 3 1 2
    // 1 1 2 3 5
    // 1 2 3 4 5 -> 1 + 1 + 1
    vector<int> vec(N);
    long long answer = 0;
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; i++){
        answer += abs((i+1) - vec[i]);
    }
    cout << answer << '\n';
}