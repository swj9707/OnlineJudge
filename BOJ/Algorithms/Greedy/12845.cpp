#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>());
    int maxValue = vec[0];
    int answer = 0;
    for(int i = 1; i < N; i++) answer += maxValue + vec[i];
    cout << answer << '\n';
}