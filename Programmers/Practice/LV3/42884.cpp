#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes){
    int answer = 0;
    sort(routes.begin(), routes.end());
    int camera = -987654321;
    for(int i = 0; i < routes.size(); i++){
        if(camera < routes[i][0]){
            answer++;
            camera = routes[i][1];
        }
        if(camera >= routes[i][1]) camera = routes[i][1];
    }
    return answer;
}

int main(){
    cout << solution({{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}}) << '\n';
}