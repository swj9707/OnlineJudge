#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        vector<int> data(10);
        for(int j = 0; j < 10; j++) cin >> data[i];
        int maximum = data[0];
        for(int j = 1; j < 10; j++) maximum = max(maximum, data[j]);
        cout << "#" << i+1 << " " << maximum << '\n';
    }
}