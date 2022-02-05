#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCase;
    cin >> testCase;
    for(int tc = 0; tc < testCase ; tc++){
        int N;
        int answer = 1;
        cin >> N;
        unordered_map<string, int> uom;
        string A, B;
        for(int i = 0; i < N; i++){
            cin >> A >> B;
            uom[B]++;
        }
        for(auto i : uom){
            answer *= i.second + 1;
        }
        cout << answer -1 << '\n';
    }
}