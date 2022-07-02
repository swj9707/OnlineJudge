#include <string>
#include <vector>
#define MAX 60001
#define MOD 1000000007
using namespace std;

int DP[MAX];

int solution(int n) {
    int answer = 0;
    DP[1] = 1;
    DP[2] = 2;
    for(int i = 3; i <= MAX; i++){
        DP[i] = DP[i-1] % MOD + DP[i-2] % MOD;
    }
    answer = DP[n] % MOD;
    return answer;
}