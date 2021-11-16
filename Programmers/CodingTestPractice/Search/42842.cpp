#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int height = sum / 2; height > 0; height--){
        if(!(sum % height)){
            int width = sum / height;
            if((height - 2) * (width - 2) == yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end(), comp);
    return answer;
}