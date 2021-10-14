#include <iostream>
#include <deque>
#include <vector>
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

int BFS(int X, int Y){
    deque<pair<int, int>> Q;
    int result = 0;
    Q.push_back({X, Y});
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        result += 1;
        Q.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visit[ny][nx] && MATRIX[ny][nx] == 0){
                visit[ny][nx] = true;
                Q.push_back({nx, ny});
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
        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                if(MATRIX[y][x] == 0) MATRIX[y][x] = 1;
            }
        }
    }
    int count = 0;
    vector<int> result;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << MATRIX[j][i];
        }
        cout << '\n';
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visit[j][i] && MATRIX[j][i] == 0){
                int Answer = BFS(i, j);
                result.push_back(Answer);
                count +=1;
            }
        }
    }
    cout << count << "\n";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}