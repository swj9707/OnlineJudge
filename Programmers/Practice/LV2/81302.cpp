#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool BFS(int Y, int X, vector<string> map){
    vector<vector<bool>> Visit(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{Y, X}, 0});
    Visit[Y][X] = true;

    while(!Q.empty()){
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int count = Q.front().second;
        Q.pop();
        if(count == 2) continue;
        
        for(int i = 0; i < 4; i++){
            int ny =y + dy[i];
            int nx =x + dx[i];
            if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5 && !Visit[ny][nx]){
                if(map[ny][nx] == 'O'){
                    Q.push({{ny, nx}, count + 1});
                    Visit[ny][nx] = true;
                }
                else if (map[ny][nx] == 'P') {
                    return false;
                }
            }
        }
    }
    return true;
}

int findAnswer(vector<string> map){

    for(int Y = 0; Y < map.size(); Y++){
        for(int X = 0; X < map[Y].size(); X++){
            if(map[Y][X] == 'P'){
                if(BFS(Y, X, map) == false){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> func(vector<vector<string>> places){
    vector<int> result;
    for(int i = 0; i < places.size(); i++){
        result.push_back(findAnswer(places[i]));
    }
    return result;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer = func(places);
    return answer;
}