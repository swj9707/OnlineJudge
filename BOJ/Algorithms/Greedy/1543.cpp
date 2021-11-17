#include <iostream>
#include <string>
using namespace std;

int main(){
    string tmp, find;
    getline(cin, tmp);
    getline(cin, find);
    int answer = 0;
    if(find.length() > tmp.length()) {
        cout << "0\n"; return 0;
    }
    else{
        for(int i = 0; i < tmp.length(); i++){
            bool flag = true;
            for(int j = 0; j < find.length(); j++){
                if(tmp[i+j] != find[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                answer++;
                i += find.length()-1;
            }
        }
    }
    cout << answer;
}