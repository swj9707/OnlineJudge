#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, N;
    cin >> A >> B;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    int answer = abs(A - B);
    for(int i = 0; i < N; i++){
        int count = abs(vec[i] - B) + 1;
        answer = min(answer, count);
    }
    cout << answer << '\n';
}