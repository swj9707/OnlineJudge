#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, K, C; cin >> L >> K >> C;
    vector<int> vec;
    for(int i = 0; i < K; i++){
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int left = 0, right = vec.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        
    }
}