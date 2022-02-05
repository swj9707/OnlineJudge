#include <iostream>

using namespace std;
int DP[501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int answer = 0;
    cin >> N;
    for(int i = 1; i <= N; i++){
        int count = 0;
        int tmp = i;
        while(true){
            if(tmp % 5 == 0){
                count++;
                tmp /= 5;
            }
            else break;
        }
        DP[i] = count;
    }
    for(int i = 1; i <= N; i++) answer += DP[i];
    cout << answer << '\n';
}