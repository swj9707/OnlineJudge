#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;
int count[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int answer = 0;
    vector<int> data(N);
    for(int i = 0; i < N; i++) cin >> data[i];
    for(int i = 0; i < N; i++) count[data[i]] += 1;
    for(int i = 0; i < N; i++) answer = max(answer, count[i]);
    cout << answer << '\n';
}