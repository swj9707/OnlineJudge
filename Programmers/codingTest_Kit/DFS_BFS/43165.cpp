#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int sum, int count){
    if(numbers.size() == count){
        if(sum == target) answer++;
        return;
    }
    DFS(numbers, target, sum + numbers[count], count+1);
    DFS(numbers, target, sum - numbers[count], count+1);
}

int solution(vector<int> numbers, int target){
    DFS(numbers, target, 0, 0);
    return answer;
}

int main(){
    vector<int> inputData = {1,1,1,1,1};
    int target = 3;
    cout << solution(inputData, target) << '\n';
    return 0;
} 