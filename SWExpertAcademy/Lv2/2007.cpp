#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string tmp;
        cin >> tmp;
        char first = tmp[0];
        int count = 1;
        for(int j = 1; j < tmp.size(); j++){
            if(first == tmp[j]) break;
            else count += 1;
        }
        cout << "#" << i+1 << " " << count;
        cout << "\n";
    }
}