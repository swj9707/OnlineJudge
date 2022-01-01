#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

vector <int> vec[MAX];
vector <int> check;
bool Visit[MAX];
int N, M;

void 

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        vec[b].push_back(a);
    }
}