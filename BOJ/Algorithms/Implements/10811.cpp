#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0; i < N; i++) v.push_back(i+1);
    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        reverse(&v[start-1], &v[end]);
    }
    for(int i = 0; i < N; i++) cout << v[i] << " ";
}