#include <iostream>

using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    int Answer = 0;
    for(int i = 0; i <= K; i++){
        int girls = N - i;
        int boys = M - (K - i);
        if(girls > 0 && boys > 0){
            int team = girls / 2;
            if(boys < team) team = boys;
            if(team > Answer) Answer = team;
        }
    }
    cout << Answer << "\n";
}