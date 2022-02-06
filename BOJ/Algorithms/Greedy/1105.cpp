#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string L, R;
    cin >> L >> R;
    int answer = 0;
    if(L.length() == R.length()){
        for(int i = 0; i < L.length(); i++){
            if(L[i] != R[i]) break;
            if(L[i] == R[i] && L[i] == '8') answer++;
        }
    }
    cout << answer << '\n';
}