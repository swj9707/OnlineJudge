#include <iostream>

using namespace std;

int countWater(int water){
    int count = 0;
    while(water > 0){
        if(water % 2 == 1) count++;
        water /= 2;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int answer = 0;
    if(N <= K) {
        cout << "0\n";
    }
    else{
        while(1){
            if(countWater(N) <= K) break;
            answer++;
            N++;
        }
        cout << answer << '\n';
    }
}