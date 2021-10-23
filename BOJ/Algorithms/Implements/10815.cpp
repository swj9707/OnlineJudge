#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<int> cards(N);
    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        int data;
        cin >> data;
        int result = binary_search(cards.begin(), cards.end(), data);
        cout << result << " ";
    }
}