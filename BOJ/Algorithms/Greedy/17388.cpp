#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int S, K, H;
    cin >> S >> K >> H;
    if(S + K + H >= 100) cout << "OK\n";
    else{
        int minValue = min(S, min(K, H));
        if(minValue == S) cout << "Soongsil\n";
        else if(minValue == K) cout << "Korea\n";
        else cout << "Hanyang\n";
    }
    return 0;
}