#include <iostream>
#define MAX 10
using namespace std;
int N, M;
bool areFriends[MAX][MAX];

int countPairings(bool taken[10]){
    int firstFree = -1;
    for(int i = 0; i < N; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = firstFree + 1; pairWith < N; ++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        cin >> N >> M;
        for(int i = 1; i <= M; i++){
            int src, dst;
            cin >> src >> dst;
            areFriends[src][dst] = true;
            areFriends[dst][src] = true;
        }

    }
}