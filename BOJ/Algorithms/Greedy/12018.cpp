#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> result;
    int answer = 0;
    while(N--){
        int P, L;
        cin >> P >> L;
        vector<int> vecP(P);
        for(int i = 0; i < P; i++) cin >> vecP[i];
        sort(vecP.begin(), vecP.end(), greater<int>());
        if(P >= L){
            int lowerbound = vecP[L - 1];
            result.push_back(lowerbound);
        }
        else{
            result.push_back(1);
        }
    }
    sort(result.begin(), result.end());
    for(auto i : result){
        if(M - i >= 0){
            M -= i;
            answer++;
        }
        else break;
    }
    cout << answer << '\n';
}