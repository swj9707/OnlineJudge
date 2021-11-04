#include <iostream>
#define MAX 301

using namespace std;

int Data[MAX];
int DP[MAX];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> Data[i];
    }
    DP[1] = Data[1];
    DP[2] = Data[1] + Data[2];
    DP[3] = max(Data[1] + Data[3], Data[2] + Data[3]);
    
    for (int i = 4; i <= N; i++)
    {
        DP[i] = max(DP[i - 2] + Data[i], DP[i - 3] + Data[i-1] + Data[i]);
    }

    cout << DP[N] << '\n';
}