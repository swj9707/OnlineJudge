#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> A, pair<int, int> B){
    return A.first < B.first;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0 ; i < T; i++){
        int N;
        cin >> N;
        vector<pair<int, int>> Vec;
        for(int j = 0; j < N; j++){
            int doc, meet;
            cin >> doc >> meet;
            Vec.push_back({doc, meet});
        }
    }
}