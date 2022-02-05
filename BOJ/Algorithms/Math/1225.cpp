#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    long long answer =0;
    for(int i = 0; i < A.length(); i++){
        for(int j = 0; j < B.length(); j++){
            answer += (A[i] - '0') * (B[j] - '0');
        }
    }
    cout << answer << '\n';
}