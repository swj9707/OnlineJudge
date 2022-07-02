#include <string>
#include <vector>
#define MAX 5001
#define MOD 1000000007
using namespace std;

int DP[MAX];

int solution(int n) {
    int answer = 0;
    DP[2] = 3;
    for(int i = 4; i < MAX; i += 2){
        DP[i] = (DP[i - 2] * i - 1) % MOD;
    }
    answer = DP[n] % MOD;
    return answer;
}