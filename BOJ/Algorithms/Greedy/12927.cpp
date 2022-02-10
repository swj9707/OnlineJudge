#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string bulb = "N";
    string tmp;
    cin >> tmp;
    bulb += tmp;
    int count = 0;
    for(int i = 1; i < bulb.length(); i++){
        if(bulb[i] == 'Y'){
            for (int j = i; j < bulb.length(); j += i){
                if(bulb[j] == 'Y') bulb[j] = 'N';
                else bulb[j] = 'Y';
            }
            count += 1;
        }
    }
    
    cout << count << '\n';
}