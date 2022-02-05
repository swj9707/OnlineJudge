#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(cin >> N){
        int tmp = 0;
        for(int i = 1;  i <= N; i++){
            tmp = tmp * 10 + 1;
            tmp %= N;
            if(tmp == 0){
                cout << i << '\n';
                break;
            }
        }
    }
}