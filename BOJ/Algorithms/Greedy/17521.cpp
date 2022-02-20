#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, W;
    cin >> N >> W;
    vector<int> dataList(N);
    for(int i = 0; i < N; i++) cin >> dataList[i];
    for(int i = 0; i < N - 1; i++){
        if(dataList[i] < dataList[i+1]){
            if((W / dataList[i]) > 0){
                long long tmp = W / dataList[i];
                W %= dataList[i];
                tmp = dataList[i+1] * tmp;
                W += tmp;
            }
        }
    }
    cout << W << '\n';
}