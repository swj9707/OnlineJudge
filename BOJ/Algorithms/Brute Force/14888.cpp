#include <iostream>

using namespace std;

int bruteForceMax(int * nums, int N,  int * operators){
    int Answer = 0;
    int MAX = -99999;
    for(int i = 0; i < N; i++){
        int max = 0;
        for(int j = 0; j < 4; j++){

        }
    }    
    return Answer;
}
int bruteForceMin(int * nums, int N, int * operators){
    int Answer = 0;
    int Min = 99999;
    return Answer;
}

int main(){
    int N;
    int nums[11];
    int operators[4];
    cin >> N;
    for(int i = 0; i < N ;i++) cin >> nums[i];
    for(int i = 0; i < 4; i++) cin >> operators[i];
    cout << bruteForceMax(nums, N, operators) << '\n';        
    cout << bruteForceMin(nums, N, operators) << '\n';        
}