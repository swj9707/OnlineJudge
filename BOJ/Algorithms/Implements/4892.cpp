#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = -1;
    int count = 1;
    while(1){
        cin >> N;
        if(N == 0) break;
        if(N % 2 == 0) cout << count << ". even " << N / 2 << '\n';
        else cout << count << ". odd " << N / 2 << '\n';
        count++;
    }
    return 0;
}