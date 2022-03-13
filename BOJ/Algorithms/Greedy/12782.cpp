#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        string a, b; cin >> a >> b;
        int a_one = 0;
        int b_one = 0;
        int diff = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]) diff++;
            if(a[i] == '1') a_one++;
            if(b[i] == '1') b_one++;
        }
        cout << (abs(a_one - b_one) + diff) / 2 << '\n';
    }
}