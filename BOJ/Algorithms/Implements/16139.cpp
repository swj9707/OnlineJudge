#include <iostream>
#define MAX 200001
using namespace std;

int countArray[26][MAX];

void setting(string inputData){
    for(int i = 0; i < 26; i++){
        char alphabet = i + 'a';
        for(int j = 0; j < inputData.size(); j++){
            countArray[i][j] = countArray[i][j-1] + ((inputData[j] == alphabet) ? 1 : 0);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp; cin >> tmp;
    int N; cin >> N;
    setting(tmp);
    char alpha;
    int start, end;
    while(N--){
        cin >> alpha >> start >> end;
        cout << countArray[alpha - 'a'][end] - countArray[alpha - 'a'][start - 1] << '\n';
    }
}