#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> data;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    int halfIndex = data.size() / 2;
    cout << data[halfIndex] << '\n';
}