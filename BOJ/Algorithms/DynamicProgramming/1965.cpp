#include <iostream>
#define MAX 1001
using namespace std;

int DP[MAX];
int Arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int answer = 0;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    for(int i = 1; i <= N; i++){
        int maxValue = 0;
        for(int j = 1; j <= i; j++){
            if(Arr[i] > Arr[j]){
                if(maxValue < DP[j]) maxValue = DP[j];
            }
        }
        DP[i] = maxValue + 1;
        answer = max(answer, DP[i]);
    }
    cout << answer << '\n';
}