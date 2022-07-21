#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int MaxValue = -987654321;
int MinValue = 987654321;
int MATRIX[MAX];
int Plus, Minus, Mult, Div;


void DFS(int count, int N, int plus, int minus, int mult, int div, int sum){
    if(count == N){
        MinValue = min(MinValue, sum);
        MaxValue = max(MaxValue, sum);
        return;
    }

    if(plus < Plus) DFS(count + 1, N, plus + 1, minus, mult, div, sum + MATRIX[count]);
    if (minus < Minus) DFS(count + 1, N, plus, minus + 1, mult, div, sum - MATRIX[count]);
    if(mult < Mult) DFS(count + 1, N, plus, minus, mult + 1, div, sum * MATRIX[count]);
    if (div < Div) DFS(count + 1, N, plus, minus, mult, div + 1, sum / MATRIX[count]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        cin >> MATRIX[i];
    }
    cin >> Plus >> Minus >> Mult >> Div;

    DFS(1, N, 0, 0, 0, 0, MATRIX[0]);

    cout << MaxValue << "\n";
    cout << MinValue << "\n";
}