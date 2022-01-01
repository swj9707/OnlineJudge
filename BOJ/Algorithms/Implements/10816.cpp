#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> first(N);
    for(int i = 0; i < N; i++){
        cin >> first[i];
    }
    sort(first.begin(), first.end());
    int M;
    cin >> M;
    vector<int> second(M);
    for(int i = 0; i < M; i++){
        cin >> second[i];
    }
    for(int i = 0; i < M; i++){
        cout << upper_bound(first.begin(), first.end(), second[i]) - lower_bound(first.begin(), first.end(), second[i]) << " ";
    }
    cout << '\n';
}