#include <string>
#include <vector>
#include <iostream>
#define MAX 50
#define INF 987654321
using namespace std;
bool Visit[50];
int answer = INF;

int cmpString(string A, string B, int N){
    int result = 0;
    for(int i = 0; i < N; i++){
        if(A[i] != B[i]) result++;
    }
    return result;
}
void DFS(string data, string target, vector<string> words, int count){
    if(data == target) {
        answer = min(answer, count);
        return;
    }
    for(int i = 0; i < words.size(); i++){
        if(cmpString(data, words[i], data.length())==1){
            if(!Visit[i]){
                Visit[i] = true;
                DFS(words[i], target, words, count+1);
                Visit[i] = false;}
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    DFS(begin, target, words, 0);
    if(answer == INF) return 0;
    return answer;
}