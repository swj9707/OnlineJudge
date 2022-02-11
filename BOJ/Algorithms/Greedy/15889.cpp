#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> pointList(N);
    for(int i = 0; i < N; i++) cin >> pointList[i];
    if(N != 1){
        vector<int> rangeList(N-1);
        for(int i = 0; i < N-1; i++) cin >> rangeList[i];
        int maxRange = 0;
        for(int i = 0; i < N-1; i++){
            maxRange = max(maxRange, pointList[i] + rangeList[i]);
            if(maxRange >= pointList[i+1]) continue;
            else{
                cout << "엄마 나 전역 늦어질 것 같아\n";
                return 0;
            }
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다\n";
    return 0;
}