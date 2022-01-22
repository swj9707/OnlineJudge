#include <iostream>

using namespace std;

int Arr[30001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int answer = 0;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    for(int i = 1; i < N; i++){
        int count = 0;
        for(int j = i+1; j <= N; j++){
            if(Arr[i] > Arr[j]) count++;
            else break;
        }
        answer = max(count, answer);
    }
    cout << answer << '\n';
}