#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B; cin >> A >> B;
    int N = A + B;
    int answer = 0;
    unordered_map<int, int> uom;
    while(N--){
        int tmp; cin >> tmp;
        uom[tmp]++;
    }
    for(auto i : uom){
        if(i.second == 1) answer++;
    }
    cout << answer << '\n';
}