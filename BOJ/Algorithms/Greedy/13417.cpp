#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        deque<char> data;
        string answer = "";
        int N;
        cin >> N;
        while(N--){
            char A;
            cin >> A;
            if(A > data.front()){
                data.push_back(A);
            }
            else data.push_front(A);
        }
        while(!data.empty()){
            answer.push_back(data.front());
            data.pop_front();
        }
        cout << answer << '\n';
    }
}