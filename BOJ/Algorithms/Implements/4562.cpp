#include <iostream>

using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int a, b; cin >> a >> b;
        if(a < b) cout << "NO BRAINS\n";
        else cout << "MMM BRAINS\n";
    }
}