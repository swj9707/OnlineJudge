#include <bits/stdc++.h>
#define MAX 10
using namespace std;

bool Visit[MAX];
int MATRIX[MAX];
char DATA[MAX];
vector<string> ans;


bool checkData(int N){
    for(int i = 1; i < N; i++){
        if(DATA[i] == '>'){
            if(MATRIX[i] < MATRIX[i+1]) return false;
        } else if (DATA[i] == '<'){
            if(MATRIX[i] > MATRIX[i+1]) return false;
        }
    }
    return true;
}

void DFS(int count, int N){
    if(count == N){
        if(checkData(N)){
            string tmp = "";
            for(int i = 1; i <= N; i++){
                tmp += MATRIX[i] + '0';
            }
            ans.push_back(tmp);
        }
    }

    for(int i = 1; i <= N; i++)

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


}