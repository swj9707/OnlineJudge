#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int N, M;
int MATRIX[MAX];
int DATA[MAX];
bool Visit[MAX];
set<vector<int>> st;
void DFS(int num, int count){
    if(count == M){
        vector<int> tmp;
        for(int i = 0; i < M; i++){
            tmp.push_back(DATA[MATRIX[i]]);
        }
        st.insert(tmp);
    }
    for(int i = num; i <= N; i++){
        if(!Visit[i]){
            Visit[i] = true;
            MATRIX[count] = i;
            DFS(i, count + 1);
            Visit[i] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    sort(DATA + 1, DATA + 1 + N);
    DFS(1, 0);

    for(auto vec : st){
        for(auto tmp : vec){
            cout << tmp << " ";
        }
        cout << '\n';
    }


}