#include <iostream>
#define MAX 1000001
using namespace std;

long long Arr[MAX * 4];

void update(int node, long long val){
    while(node > 0){
        Arr[node] += val;
        node /= 2;
    }
}

long long get(int s, int e){
    long long ans = 0;
    while(s <= e){
        if(s % 2 == 1) ans += Arr[s];
        if(e % 2 == 0) ans += Arr[e];
        s = (s + 1) / 2;
        e = (e - 1) / 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int s = 1;
    while(s < N){
        s *= 2;
    }
    for(int i = 0; i < N; i++) cin >> Arr[i+s];
    for(int i = s - 1; i >= 1; i--){
        Arr[i] = Arr[2*i] + Arr[2*i+1];
    }
    for(int i = 0; i < M + K; i++){
        int a;
        long long b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b + s - 1, c - Arr[b + s - 1]);
        }
        else{
            cout << get(b + s - 1, c + s - 1) << '\n';
        }
    }
    return 0;
}