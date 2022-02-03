#include <iostream>
#define MAX 21
using namespace std;

int arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int Y = 0, M = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
        Y += (arr[i] / 30 + 1) * 10;
        M += (arr[i] / 60 + 1) * 15;
    }
    if(Y > M) cout << "M " << M << '\n';
    else if(Y < M) cout << "Y " << Y << '\n';
    else cout << "Y M " << Y << '\n';
}