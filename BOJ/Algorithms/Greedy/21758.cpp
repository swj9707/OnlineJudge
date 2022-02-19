#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> data(N);
    vector<int> sumofData(N);
    for(int i = 0; i < N; i++){
        cin >> data[i];
        sumofData[i] = data[i];
    }
    for(int i = 1; i < N; i++) sumofData[i] += sumofData[i-1];
    int answer = 0;
    for(int i = 1; i < N-1; i++){
        answer = max(answer, 2*sumofData[N-1]-data[0]-data[i]-sumofData[i]);
    }
    for(int i = 1; i < N-1; i++){
        answer = max(answer, sumofData[N-1]-data[N-1]-data[i]+sumofData[i-1]);
    }
    for(int i = 1; i < N-1; i++){
        answer = max(answer, sumofData[i]-data[0] + sumofData[N-1]-sumofData[i-1]-data[N-1]);
    }
    cout << answer << '\n';
}