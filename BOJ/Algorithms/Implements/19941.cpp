#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    vector<char> vec;
    cin >> N >> K;
    int answer = 0;
    for(int i = 0; i < N; i++){
        char tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    for(int i = 0; i < N; i++){
        if (vec[i] != 'P') continue;
        for(int j = i - K; j <= i + K; j++){
            if(0 <= j && j < N && vec[j] == 'H'){
                vec[j] = 'X';
                answer++;
                break;
            }
        }
    }
    cout << answer << '\n';
}