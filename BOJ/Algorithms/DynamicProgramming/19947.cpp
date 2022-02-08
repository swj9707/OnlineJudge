#include <iostream>
#define MAX 11
using namespace std;

int DP[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int H, Y;
    cin >> H >> Y;
    DP[0] = H;
    for(int i = 1; i <= Y; i++){
        DP[i] = (int)(DP[i-1]*1.05);
        if(i >= 3){
            DP[i] = max(DP[i], (int)(DP[i-3] * 1.2));
        }
        if(i >= 5){
            DP[i] = max(DP[i], (int)(DP[i-5] * 1.35));
        }
    }
    cout << DP[Y] << '\n';
}