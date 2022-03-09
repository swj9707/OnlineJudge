#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 101
using namespace std;

vector<pair<double, double>> pointData;
vector<pair<int, double>> edge[MAX];
bool visited[MAX];

double prim(){
    double result = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> PQ;
    PQ.push({0, 0});
    while(!PQ.empty()){
    	int next = PQ.top().second;
        double minCost = PQ.top().first;
        PQ.pop();
    	if(!visited[next]){
        	visited[next] = true;
            result += minCost;
            for(auto X : edge[next]){
                if(!visited[X.first]) PQ.push({X.second, X.first});
            }
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        double a, b;
        cin >> a >> b;
        pointData.push_back({a, b});
    }
    for(int i = 0; i < N; i++){
        double x = pointData[i].first;
        double y = pointData[i].second;
        for(int j = i + 1; j < N; j++){
            double xx = pointData[j].first;
            double yy = pointData[j].second;
            
            double dx = pow((x - xx),2);
            double dy = pow((y - yy), 2);
            double dist = sqrt(dx + dy);
            edge[i].push_back({j, dist});
            edge[j].push_back({i, dist});
        }
    }
    double answer = prim();
    cout << answer << '\n';
}