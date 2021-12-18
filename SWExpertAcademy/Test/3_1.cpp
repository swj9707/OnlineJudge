#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(T vec){
    for(auto a : vec){
        std::cout << a <<" ";
    }
    std::cout << '\n';
}

int main(){
    int T;
    cin >> T;
    for(int caseNum = 1; caseNum <= T; caseNum++){
        int answer = 0;
        int N;
        cin >> N;
        vector<int> mapData(N);
        for(int i = 0; i < N; i++) cin >> mapData[i];
        
        cout << "#" << caseNum << " " << answer <<'\n';
    }
}