#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int N, M;
    int a[500001];
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    cin >> M;
    for(int i = 0; i < M; i++){
        int data;
        cin >> data;
        int result = binary_search(a, a + N, data);
        cout << result << " ";
    }
}