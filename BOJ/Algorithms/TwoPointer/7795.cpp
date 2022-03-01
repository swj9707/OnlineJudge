#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        int answer = 0;
        vector<int> vecA(N);
        vector<int> vecB(M);
        for(int i = 0; i < N; i++) cin >> vecA[i];
        for(int i = 0; i < M; i++) cin >> vecB[i];
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end());
        for(int i = 0; i <  N; i++){
            for(int j = 0; j < M; j++){
                if(vecA[i] > vecB[j]){
                    answer++;
                }
                else break;
            }
        }
        cout << answer << '\n';
    }
}