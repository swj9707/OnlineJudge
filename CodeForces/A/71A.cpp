#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        if(tmp.length() <= 10) cout << tmp << '\n';
        else{
            int count = tmp.length() - 2;
            cout << tmp[0] << count << tmp[tmp.length()-1] << '\n';
        }
    }
}