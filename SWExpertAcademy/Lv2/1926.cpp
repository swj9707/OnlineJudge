#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        string Data = to_string(i);
        int count = 0;
        for(int j = 0; j < Data.size(); j++){
            if(Data[j] == "3" ||  Data[j] == "6" || Data[j] == "9"){
                count += 1;
            }
        }
        if(count == 0) cout << i;
        else{
            for(int j = 0; j < count ; j++){
                cout << "-";
            }
        }
        cout << " ";    
    }
}