#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

bool Visit[MAX];
int parent[MAX];
vector<int> Tree[MAX];

void DFS(int V){
    Visit[V] = true;
    for(int i = 0; i < Tree[V].size(); i++){
        int next = Tree[V][i];
        if(!Visit[next]){
            parent[next] = V;
            DFS(next);
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int A, B;
        cin >> A >> B;
        Tree[A].push_back(B);
        Tree[B].push_back(A);
    }
    DFS(1);
    for(int i = 2 ; i <= N; i++) cout << parent[i] << '\n';
}