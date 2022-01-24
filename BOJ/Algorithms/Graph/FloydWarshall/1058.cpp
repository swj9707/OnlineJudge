#include <bits/stdc++.h>
#define MAX 51
#define INF 987654321
using namespace std;

vector<int> vec[MAX];
int MATRIX[MAX][MAX];
int N;
void solve(){
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (MATRIX[i][k] != INF && MATRIX[k][j] != INF)
                {
                    if(i == j) continue;
                    else MATRIX[i][j] = min(MATRIX[i][j], MATRIX[i][k] + MATRIX[k][j]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    int answer = 0;
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++) MATRIX[i][j] = INF;
    }
    for(int i = 1; i <= N; i++){
        cin >> tmp;
        for(int j = 0; j < N; j++){
            if(tmp[j] == 'Y'){
                MATRIX[i][j+1] = 1;
            }
        }
    }
    solve();
    for (int i = 1; i <= N; i++){
        int count = 0;
        for (int j = 1; j <= N; j++){
            if(MATRIX[i][j] <= 2) count++;
        }
        answer = max(answer, count);
    }
    cout << answer << '\n';
}