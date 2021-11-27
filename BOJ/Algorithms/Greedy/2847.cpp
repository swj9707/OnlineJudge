#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    int answer = 0;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    for(int i = N - 2; i >= 0; i--){
        if(vec[i] >= vec[i + 1]){
            while(vec[i] >= vec[i+1]){
                vec[i] -= 1;
                answer++;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}