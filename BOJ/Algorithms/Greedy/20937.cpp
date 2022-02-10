#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;
int Count[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int answer = -1;
    vector<int> data(N);
    for(int i = 0; i < N; i++) cin >> data[i];
    for(int i = 0; i < N; i++) Count[data[i]] += 1;
    for(int i = 0; i < MAX; i++) answer = max(answer, Count[i]);
    cout << answer << '\n';
}