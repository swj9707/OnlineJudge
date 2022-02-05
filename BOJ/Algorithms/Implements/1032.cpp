#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    string tmp[50];
    for(int i = 0; i < N; i++) cin >> tmp[i];
    char c;
    for(int i = 0; i < tmp[0].size(); i++){
        char c = tmp[0][i];
        for(int j = 1; j < N; j++){
            if(c != tmp[j][i]){
                c = '?';
            }
        }
        cout << c;
    }
}