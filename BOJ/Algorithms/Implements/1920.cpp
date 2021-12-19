#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int M;
    cin >> M;
    vector<int> Data(M);
    for(int i = 0; i < M; i++) cin >> Data[i];
    sort(A.begin(), A.end());
    for(int i = 0; i < M; i++){
        cout << binary_search(A.begin(), A.end(), Data[i]) << '\n';
    }
    return 0;    
}