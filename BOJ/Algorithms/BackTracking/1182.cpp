#include <iostream>
#define MAX 20
using namespace std;

int arr[MAX];
int count;

void DFS(int cnt, int sum, int N, int S){
    if(cnt == N) return;
    if(sum + arr[cnt] == S) count++;
    DFS(cnt + 1, sum, N, S);
    DFS(cnt + 1, sum + arr[cnt], N, S);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S; 
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];
    DFS(0, 0, N, S);

    cout << count << '\n';
}