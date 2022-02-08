#include <string>
#include <vector>
#define MAX 1000001
using namespace std;

int DP1[MAX];
int DP2[MAX];

int solution(vector<int> money) {
    DP1[0] = money[0];
    DP1[1] = money[0];
    DP2[1] = money[1];

    for(int i = 2; i < money.size()-1; i++){
        DP1[i] = max(DP1[i-1], DP1[i-2] + money[i]);
    }
    for(int i = 2; i < money.size(); i++){
        DP2[i] = max(DP2[i-1], DP2[i-2] + money[i]);
    }
    return max(DP1[money.size()-2], DP2[money.size()-1]);
}