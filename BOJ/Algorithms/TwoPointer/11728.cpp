#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> A(N); vector<int> B(M);
    vector<int> Answer;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    int A_idx = 0, B_idx = 0;
    while(A_idx < N && B_idx < M){
        if(A[A_idx] < B[B_idx]) Answer.push_back(A[A_idx++]);
        else Answer.push_back(B[B_idx++]);
    }
    while(A_idx < N) Answer.push_back(A[A_idx++]);
    while(B_idx < M) Answer.push_back(B[B_idx++]);
    for(int i = 0; i < Answer.size(); i++) cout << Answer[i] << " ";
}