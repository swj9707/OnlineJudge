#include <bits/stdc++.h>

using namespace std;

int DP[21][21][21];

int dnq(int a, int b, int c){
    
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    if(a > 20 || b > 20 || c > 20){
        return dnq(20, 20, 20);
    }
    if(DP[a][b][c]){
        return DP[a][b][c];
    }
    if(a < b && b < c){
        DP[a][b][c] = dnq(a, b, c-1) + dnq(a, b-1, c-1) - dnq(a, b - 1, c);
        return DP[a][b][c];
    }
    DP[a][b][c] = dnq(a-1, b, c) + dnq(a-1, b-1, c) + dnq(a-1, b, c-1) - dnq(a-1, b-1, c-1);
    return DP[a][b][c];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){
            break;
        }
        cout << "W("<< a << ", "<< b <<", " << c <<") = " << dnq(a, b, c) << "\n";
    }
}