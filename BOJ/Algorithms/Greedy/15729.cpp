#include <bits/stdc++.h>
#define MAX 1000003
using namespace std;

int arr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] == 1){
            answer++;
            arr[i+1] = !arr[i+1];
            arr[i+2] = !arr[i+2];
        }
    }
    cout << answer << '\n';
}