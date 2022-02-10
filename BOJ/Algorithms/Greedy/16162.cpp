#include <iostream>
#define MAX 20001
using namespace std;
int Arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, A, D;
    int answer = 0;
    cin >> N >> A >> D;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    int start = A;
    for(int i = 1; i <= N; i++){
        if(Arr[i] == start){
            answer++;
            start += D;
        }
    }
    cout << answer << '\n';
}