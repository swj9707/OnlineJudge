#include <iostream>
#define MAX 100001
using namespace std;

int DP[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        DP[i] = DP[i - 1] + num;
    }
    for(int i = 1; i <= M; i++){
        int A, B;
        cin >> A >> B;
        cout << DP[B] - DP[A-1] << '\n';
    }
}