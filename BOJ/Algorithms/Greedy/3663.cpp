#include <iostream>
#include <string>

using namespace std;

int solve(string input){
    int result = 0;
    for(auto i : input) result += min(i - 'A', 'Z' + 1 - i);
    int len = input.length();
    int move = len - 1;
    for(int i = 0; i < len; i++){
        int next = i + 1;
        while(next < len && input[next] == 'A') next++;
        move = min(move, i + (len - next) + min(i, len-next));
    }
    result += move;
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    for(int T = 0; T < tc ; T++){
        string input;
        cin >> input;
        cout << solve(input) << '\n';
    }
}