#include <iostream>
#include <algorithm>
using namespace std;

int DP[16];
int T[16];
int P[16];

int solve(int N, int day){
    if(day > N + 1) return -1000000;
    if(day == N + 1) return 0;
    int ret = DP[day];
    if(ret != -1) return ret;
    ret = max(solve(N, day+1), solve(N, day + T[day]) + P[day]);
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> P[i];
        DP[i] = -1;
    }
    int answer = solve(N, 1);
    cout << answer << '\n';
}