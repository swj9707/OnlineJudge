#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    vector<int> tmp;
    tmp.assign(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    vector<int> answer(N);
    int count = 0;
    for(int i = 0; i < N; i++){
        int cmp = tmp[i];
        for(int j = 0; j < N; j++){
            if(cmp == vec[j]){
                answer[j] = count++;
                vec[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << '\n';
    return 0;
}