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
        sort(Vec.begin(), Vec.end());
        int Answer = 1;
        int tmp = Vec[0].second;
        for(int j = 1; j < Vec.size(); j++){
            if(Vec[j].second < tmp){
                Answer++;
                tmp = Vec[j].second;
                if(tmp == 1) break;
            }
        }
        cout << Answer << '\n';
    }
}