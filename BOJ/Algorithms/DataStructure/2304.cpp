#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    int leftSide = 0;
    int rightSide = 0;
    for(int i = 0; i < N; i++){
        int L, H;
        cin >> L >> H;
        vec.push_back({L, H});
    }

    sort(vec.begin(), vec.end(), [](auto a, auto b) {
        if (a.first < b.first) return true;
        else return false;
    });
    int leftLocate = vec[0].first;
    int leftMax = vec[0].second;
    for(int i = 0; i < vec.size(); i++){
        if(leftMax <= vec[i].second){
            leftSide += (vec[i].first - leftLocate) * leftMax;
            leftMax = vec[i].second;
            leftLocate = vec[i].first;
        }
    }

    int rightLocate = vec.back().first;
    int rightMax = vec.back().second;
    for(int i = vec.size() - 1; i >= 0; i--){
        if(rightMax <= vec[i].second){
            rightSide += (rightLocate - vec[i].first) * rightMax;
            rightMax = vec[i].second;
            rightLocate = vec[i].first;
        }
    }
    cout << leftSide + rightSide + leftMax << "\n";
}