#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp; cin >> tmp;
    int M; cin >> M;
    list<char> lst(tmp.begin(), tmp.end());
    list<char>::iterator now = lst.end();
    while(M--){
        char tmp;
        cin >> tmp;
        if(tmp == 'L'){
            if(now != lst.begin()){
                now--;
            }
        } else if (tmp == 'D'){
            if(now != lst.end()){
                now++;
            }
        } else if (tmp == 'B'){
            if(now != lst.begin()){
                now = lst.erase(--now);
            }
        } else if (tmp == 'P'){
            char input;
            cin >> input;
            lst.insert(now, input);
        }
    }
    for(list<char>::iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it;
    }
}