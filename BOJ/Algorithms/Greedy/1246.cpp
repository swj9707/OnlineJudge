#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> vec(M+1);
    for(int i = 1; i <= M; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long sum = 0;
    int value = 0;
    for(int i = 1; i <= M; i++){
        if(sum < vec[i] * (M - i + 1) && ((M - i + 1) <= N)){ 
            value = vec[i];
            sum = value * (M - i + 1);
        }
    }
    cout << value << " " << sum << '\n';
}