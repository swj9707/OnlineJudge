#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;

bool visit[MAX];
vector <int> v[MAX];

void DFS(int x){
    for(int i = 0; i < v[x].size(); i++){
        if(!visit[v[x][i]]){
            visit[v[x][i]] = true;
            DFS(v[x][i]);
        }
    }
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int data;
            cin >> data;
            if(data == 1)v[i].push_back(j);
        }
    }
    for(int i = 0; i < N; i++){
        memset(visit, false, sizeof(visit));
        DFS(i);
        for(int j = 0 ; j < N; j++){
            cout << visit[j] << " ";
        }
        cout << "\n";
    }
}