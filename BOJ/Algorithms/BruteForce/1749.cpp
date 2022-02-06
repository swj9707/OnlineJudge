#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string tmp = "";
    for(int i = 1; i <= N; i++){
        tmp += to_string(i);
    }
    cout << tmp.length() << '\n';
}