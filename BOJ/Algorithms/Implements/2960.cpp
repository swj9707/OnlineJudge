#include <iostream>

using namespace std;
int arr[1001];
int main(){
    int N, K;
    cin >> N >> K;
    int count = 0;
    for(int i = 2; i <= N; i++) arr[i] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 1; i * j <= N; j++){
            if(arr[i*j] == 1){
                arr[i*j] = 0;
                count++;
                if(count == K){
                    cout << i * j <<'\n';
                    return 0;
                }
            }
        }
    }
}