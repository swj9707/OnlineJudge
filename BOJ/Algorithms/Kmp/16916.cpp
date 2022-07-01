#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string data; cin >> data;
    string cmp; cin >> cmp;
    int cmpLen = cmp.length();
    int i = 0;
    do{
        string subs = data.substr(i, cmpLen);
        if(subs == cmp){
            cout << "1\n";
            return 0;
        }
        i++;
    }while(i < data.length() - cmpLen);
    cout << "0\n";
    return 0;
}