#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end(), cmp);
    long long answer = 0;
    for(int i = 0; i < N ; i++){
        if (i % 3 != 2) answer += vec[i];
    }
    cout << answer << '\n';
}