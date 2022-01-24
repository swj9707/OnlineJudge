#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
bool visitList[MAX];

int BFS(int N, int A){
    deque<int> Q;
    int result = 0;
    Q.push_back(A);
    visitList[A] = true;
    while(!Q.empty()){
        A = Q.front();
        Q.pop_front();
        for(int i = 1; i <= N; i++){
            if(matrix[A][i] && !visitList[i]){
                visitList[i] = true;
                Q.push_back(i);
                result += 1;
            }
        }
    }
    return result;
}

int main(){
    int N, M;
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        matrix[A][B] = 1;
        matrix[B][A] = 1;
    }
    int Answer = BFS(N, 1);
    cout << Answer << '\n';
}