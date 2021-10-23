#include <iostream>

using namespace std;

int combination(int n, int r){
    if(n == r || r == 0) return 1;
    else return combination(n - 1 , r - 1) + combination(n-1, r);
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        for(int j = 0; j < N; j++){
            for(int k = 0; k <= j; k++){
                cout << combination(j, k) << " ";
            }
            cout << '\n';
        }
    }
}