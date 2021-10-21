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
            if (strcmp(Data[j],"3")) cout << "-";
            else cout << Data[j];
        }
        cout << " ";    
    }
}