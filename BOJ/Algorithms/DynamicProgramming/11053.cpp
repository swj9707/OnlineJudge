#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int DP[MAX];
int Arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> data;
    int answer = 0;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        data.emplace_back(tmp);
        int maxValue = 0;
        for(int j = 0; j < data.size(); j++){
            if(data[i] > data[j]){
                if(maxValue < DP[j]) maxValue = DP[j];
            }
        }
        DP[i] = maxValue + 1;
        answer = max(answer, DP[i]);
    }
    cout << answer << '\n';
}