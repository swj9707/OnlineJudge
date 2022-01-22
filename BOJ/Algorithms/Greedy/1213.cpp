#include <bits/stdc++.h>

using namespace std;

int alphabet[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    cin >> tmp;
    for(auto i : tmp) alphabet[i - 'A']++;
}