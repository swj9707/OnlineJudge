#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int countRed =0, countBlue = 0, answer = 0;
    bool check = false;
    string tmp;
    cin >> N;
    cin >> tmp;
    for(auto i : tmp){
        if(i == 'R' && check == false){
            countRed++;
            check = true;
        }
        else if(i == 'B'){
            check = false;
        }
    }
    check = false;
    for(auto i : tmp){
        if(i == 'B' && check == false){
            countBlue++;
            check = true;
        }
        else if(i == 'R'){
            check = false;
        }
    }
    answer = min(countBlue, countRed) + 1;
    cout << answer << '\n';
}