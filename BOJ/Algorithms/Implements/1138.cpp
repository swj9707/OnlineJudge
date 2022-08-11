#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> data(N);
    for(int i = 0; i < N; i++) cin >> data[i];
    vector<int> answer(N, 0);
    for(int i = 1; i <= N; i++){
        int tmp = data[i - 1];
        int count = 0;
        for(int j = 0; j < N; j++){
            if(count == tmp && answer[j] == 0){
                answer[j] = i;
                break; 
            } else if (answer[j] == 0){
                count++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }
    cout << '\n';
}