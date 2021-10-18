#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

int Graph[MAX];
bool Visit[MAX];

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void initSet(){
    memset(Graph, 0, sizeof(Graph));
    memset(Visit, false, sizeof(Visit));
}

void DFS(int V){
    Visit[V] = true;
    if(!Visit[Graph[V]]) DFS(Graph[V]);
}

int main(){
    //init();
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        initSet();
        int N;
        cin >> N;
        for(int j = 1; j <= N; j++) cin >> Graph[j];
        int count = 0;
        for(int j = 1; j <= N; j++){
            if(!Visit[j]){
                DFS(j);
                count += 1;
            }
        }
        cout << count << "\n";
    }
}