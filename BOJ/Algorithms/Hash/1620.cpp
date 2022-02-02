#include <iostream>
#include <unordered_map>
#include <sstream>
#define MAX 100001
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_map<string, int> uom;
    string indexData[MAX];
    for(int i = 1; i <= N; i++){
        string pokemonName;
        cin >> pokemonName;
        uom[pokemonName] = i;
        indexData[i] = pokemonName;
    }
    for(int i = 0; i < M; i++){
        string tmp;
        cin >> tmp;
        if(tmp[0] >= '0' && tmp[0] <= '9'){
            stringstream ss(tmp);
            int index;
            ss >> index;
            cout << indexData[index] << '\n';
        }
        else{
            cout << uom[tmp] << '\n';
        }
    }
    return 0;
}