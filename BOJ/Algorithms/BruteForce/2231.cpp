#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        int num = i;
        int result = i;
        while(num != 0){
            result += num % 10;
            num /= 10;
        }
        if(result == N){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}