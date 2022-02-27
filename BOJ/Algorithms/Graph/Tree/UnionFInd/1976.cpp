#include <iostream>
#define MAX 201

using namespace std; 

int Parent[MAX];

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= MAX; i++) Parent[i] = i;
    int N, M; 
    cin >> N >> M;
    for(int tmp, i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> tmp;
            if(tmp == 1){
                if(!findParent(i, j)){
                    unionParent(i, j);
                }
            }
        }
    }
    int tripCourse[M];
    for(int i = 0; i < M; i++) cin >> tripCourse[i];
    for(int i = 0; i < M-1; i++){
        int src = tripCourse[i];
        int dst = tripCourse[i+1];
        if(!findParent(src, dst)){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

