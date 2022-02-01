#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int Arr[246913] = {0,};

    while(1){
        cin >> N;
        if(N == 0) break;
        int start = N + 1;
        int end = 2 * N;
        int count = 0;
        
        for(int i = 2; i <= end; i++) Arr[i] = 1;
        for(int i = 2; i <= int(sqrt(end)); i++){
            for(int j = 2; i * j <= end; j++){
                Arr[i * j] = 0;
            }
        }
        for(int i = start ; i <= end; i++){
            if(Arr[i] == 1) count++;
        }
        cout << count << '\n';
    }
}