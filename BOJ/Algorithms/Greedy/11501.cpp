#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        vector<int> vec(N);
        for(int i = 0; i < N; i++) cin >> vec[i];
        long long answer = 0;
        int maxValue = 0;
        for(int i = N - 1; i >= 0; i--){
            if(vec[i] < maxValue){
                answer += maxValue - vec[i];
            }
            else maxValue = vec[i];
        }
        cout << answer <<'\n';
    }
}