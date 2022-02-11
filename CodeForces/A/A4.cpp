#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int W;
    cin >> W;
    if(W % 2 == 0 && W > 2) cout << "YES\n";
    else cout << "NO\n";
}