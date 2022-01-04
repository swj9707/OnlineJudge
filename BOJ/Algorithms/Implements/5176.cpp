#include <iostream>
#include <vector>
using namespace std;

int main(){
    int K;
    cin >> K;
    for(int testCase = 0; testCase < K; testCase++){
        int P, M;
        cin >> P >> M;
        vector<int> vec(M+1, 0);
        int count = 0;
        for(int i = 0; i < P; i++){
            int tmp; 
            cin >> tmp;
            if(vec[tmp] == 0) vec[tmp] = 1;
            else count++;
        }
        cout << count << '\n';
    }
}