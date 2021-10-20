#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int a, b;
        cin >> a >> b;
        if(a < b) cout << "#" << i+1 << " " << "<" << '\n';
        else if(a > b) cout << "#" << i+1 << " " << ">" << '\n';
        else if(a == b) cout << "#" << i+1 << " " << "=" << '\n';
    }
}