#include <iostream>
#include <cmath>
#define MAX 100001
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Arr[MAX];
    Arr[0] = 0;
    Arr[1] = 0;
    for(int i = 2; i <= MAX; i++) Arr[i] = 1;
    for(int i = 2; i < sqrt(MAX); i++){
        for(int j = 2; j * i <= MAX; j++){
            Arr[i * j] = 0;
        }
    }
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase ; tc++){
        int N;
        cin >> N;
        for(int i = N / 2; i > 0; i--){
            if(Arr[i] == 1 && Arr[N - i] == 1){
                cout << i << " " << N - i << '\n';
                break;
            }
        }
    }
    
}