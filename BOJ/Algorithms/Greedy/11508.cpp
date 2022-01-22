#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    vector<int> vec(N);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
}