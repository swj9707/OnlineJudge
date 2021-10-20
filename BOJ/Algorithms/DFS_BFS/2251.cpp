#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 201

using namespace std;

int A, B, C;
bool visit[MAX][MAX][MAX];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> BFS(){
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(0, 0), C));
    vector<int> result;
    while(!Q.empty()){
        int a = Q.front().first.first;
        int b = Q.front().first.second;
        int c = Q.front().second;
        Q.pop();
        if(!visit[a][b][c]){
            visit[a][b][c] = true;
            if(a == 0) result.push_back(c);
            if(a + b > B) Q.push(make_pair(make_pair(a+b-B, B), c));
            else Q.push(make_pair(make_pair(0, a + b),c));
             
            if(a + c > C) Q.push(make_pair(make_pair(a+b-C, b), c));
            else Q.push(make_pair(make_pair(0, b),a + c));

            if(a + b > A) Q.push(make_pair(make_pair(A, b + a - A), c));
            else Q.push(make_pair(make_pair(a + b, 0),c));
              
            if(b + c > C) Q.push(make_pair(make_pair(a, b + c - C), C));
            else Q.push(make_pair(make_pair(a, 0), b + c));
            
            if(c + a > A) Q.push(make_pair(make_pair(A, b), c + a - A));
            else Q.push(make_pair(make_pair(c + a, b),0));

            if(c + b > B) Q.push(make_pair(make_pair(a, B), c + b - B));
            else Q.push(make_pair(make_pair(a, b + c),0));
        }
    }
    return result;
}

int main(){
    init();
    cin >> A >> B >> C;

    vector<int> result = BFS();
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << '\n';
}