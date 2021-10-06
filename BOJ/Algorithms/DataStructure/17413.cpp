#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    string S;
    getline(cin, S);
    for(int i = S.length()-1; i >= 0; i--){
        cout << S[i];
    }
    cout << '\n';
}