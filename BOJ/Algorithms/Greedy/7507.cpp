#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T ; cin >> T;
    while(T){
        int N; cin >> N;
        vector<pair<int, pair<int, int>>> vec(N);
        for(int i = 0; i < N; i++){
            cin >> vec[i].first;
            cin >> vec[i].second.first;
            cin >> vec[i].second.second;
        }

        T--;
    }
}