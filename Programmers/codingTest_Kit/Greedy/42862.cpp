#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> vec(n+2, 1);
    for(auto i : reserve) vec[i]++;
    for(auto i : lost) vec[i]--;
    for(int i = 1; i <= n; i++){
        if(vec[i] == 2 && vec[i-1] == 0){
            vec[i] = vec[i-1] = 1;
        }
        else if(vec[i] == 2 && vec[i+1] == 0){
            vec[i] = vec[i+1] = 1;
        }  
    }
    for(int i = 1; i <= n ; i++){
        if(vec[i] > 0) answer++;
    }
    return answer;
}