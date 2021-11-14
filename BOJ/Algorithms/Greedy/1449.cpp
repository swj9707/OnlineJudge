#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    vector<int> data;
    for(int i = 0; i < N; i++){
        int dt;
        cin >> dt;
        data.push_back(dt);
    }
    sort(data.begin(), data.end());
    int tmp = data[0];
    int answer = 1;
    for(int i = 1; i < data.size(); i++){
        if(data[i] - tmp + 1 > L){
            tmp = data[i];
            answer++;
        }
    }
    cout << answer << '\n';
}