#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string tmp;
        cin >> tmp;
        int count = 0;
        for(int j = 1; j < tmp.size(); j++){
            if(tmp[j] == tmp[count]) count++;
            else count = 0;
        }
        cout << "#" << i+1 << " " << (int)tmp.size() - count;
        cout << "\n";
    }
}