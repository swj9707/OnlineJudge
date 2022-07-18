#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int N, M;
int MATRIX[MAX];
int DATA[MAX];
bool VISIT[MAX];
set <vector<int>> st;
void DFS(int count){
    if(count == M){
        vector<int> tmp;
        for(int i = 0; i < M; i++){
            tmp.push_back(DATA[MATRIX[i]]);
        }
        st.insert(tmp);
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!VISIT[i]){
            VISIT[i] = true;
            MATRIX[count] = i;
            DFS(count + 1);
            VISIT[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    sort(DATA+1, DATA + N + 1);
    DFS(0);

    for(auto vec : st){
        for(auto tmp : vec){
            cout << tmp << " ";
        }
        cout << '\n';
    }
}