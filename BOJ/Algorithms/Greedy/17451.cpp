#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long answer = 0;
    int N;
    cin >> N;
    vector<long long> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    for(int i = N - 1; i >= 0; i--){
        if(answer <= vec[i]) answer = vec[i];
        else{
            if(answer % vec[i]){
                answer = (answer / vec[i] + 1) * vec[i];
            }
        }
        cout << answer << " " << vec[i] << '\n';
    }
    cout << answer << '\n';
}