#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int count = 0;
    int answer = 0;
    int num = 666;
    while(count != N){
        string tmp = to_string(num);
        for(int i = 0; i < tmp.length() - 2; i++){
            if(tmp[i] == '6' && tmp[i+1] == '6' && tmp[i+2] == '6'){
                count++;
                if(count == N){
                    answer = num;
                }
                break;
            }
        }
        num++;
    }
    cout << answer << '\n';
}