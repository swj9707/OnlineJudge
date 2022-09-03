#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    while(cin >> s >> t){
        int idx = 0;
        bool result = false;
        for(int i = 0; i < t.length(); i++){
            if(s[idx] == t[i]){
                idx++;
            }
            if(idx == s.length()){
                result = true;
                break;
            }
        }
        if(result){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}