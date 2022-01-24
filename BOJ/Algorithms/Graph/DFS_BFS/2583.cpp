#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int MATRIX[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int M, N, K;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int BFS(int Y, int X){
    deque<pair<int, int>> Q;
    int result = 0;
    Q.push_back({Y, X});
    visit[Y][X] = true;
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        result += 1;
        Q.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[ny][nx] && MATRIX[ny][nx] == 0){
                visit[ny][nx] = true;
                Q.push_back({ny, nx});
            }
        }
    }
    return result;
}


int main(){
    init();
    cin >> M >> N >> K;
    for(int T = 0; T < K ; T++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int deltaX = x2 - x1; int deltaY = y2 - y1;
        for(int Y = y1 ; Y < y1 + deltaY; Y++){
            for(int X = x1; X < x2; X++){
                MATRIX[Y][X] = 1;
            }
        }
    }
    int count = 0;
    vector<int> result;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visit[j][i] && MATRIX[j][i] == 0){
                int Answer = BFS(j, i);
                result.push_back(Answer);
                count +=1;
            }
        }
    }
    cout << count << "\n";
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}