#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> A, pair<int, int> B){
    if(A.second == B.second) return A.first < B.first;
    else return A.second < B.second; 
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for(int i = 0; i < N; i++){
        int first, second;
        cin >> first >> second;
        vec[i].first = first;
        vec[i].second = second;
    } 
    sort(vec.begin(), vec.end(), comp);
    for(int i = 0; i < N; i++){
        cout << vec[i].first << " " << vec[i].second << '\n';
    }       
}