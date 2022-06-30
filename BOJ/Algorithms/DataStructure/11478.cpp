#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmpStr; cin >> tmpStr;
    unordered_set<string> uos;
    for(int i = 0; i < tmpStr.length(); i++){
        string str = "";
        for(int j = i; j < tmpStr.length(); j++){
            str += tmpStr[j];
            uos.insert(str);
        }
    }
    cout << uos.size() << '\n';
}