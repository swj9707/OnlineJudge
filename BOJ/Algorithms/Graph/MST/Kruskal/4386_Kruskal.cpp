#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 101
using namespace std;

vector<pair<double, double>> pointData;
vector<pair<double, pair<double, double>>> edge;
int Parent[MAX];

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}

double kruskal(){
    double result = 0;
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        double cost = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if(!findParent(a, b)){
            unionParent(a, b);
            result += cost;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < MAX; i++) Parent[i] = i;
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
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
            edge.push_back({dist, {i, j}});
        }
    }

    double answer = kruskal();
    cout << answer << '\n';
}