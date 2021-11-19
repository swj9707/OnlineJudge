#include <iostream>
#include <string>

using namespace std;

int main(){
    while(1){
        string tmp;
        getline(cin, tmp);
        if(tmp == "") break;
        cout << tmp << "\n";       
    }
}