#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pair<int, int>> vec;
        for(int i = 1; i <= N / 2; i++){
            if((i + (N - i)) == N && i != N - i) vec.push_back({i, N - i});
        }
        cout << "Pairs for " << N << ": ";
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i].first << " " << vec[i].second;
            if(i != vec.size() - 1) cout << ", ";
        }
        cout << '\n';
    }
}