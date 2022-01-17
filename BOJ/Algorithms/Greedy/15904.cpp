#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    getline(cin, tmp);
    int count = 0;
    for(auto i : tmp){
        if(i == 'U' && count == 0) count++;
        else if(i == 'C' && count == 1) count++;
        else if(i == 'P' && count == 2) count++;
        else if(i == 'C' && count == 3) count++;
    }
    if(count == 4) cout << "I love UCPC" << '\n';
    else cout << "I hate UCPC" << '\n';
}