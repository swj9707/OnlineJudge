#include <iostream>
#include <cstring>
#include <deque>
#define MAX 301

using namespace std;

int MATRIX[MAX][MAX];
int N;
int sourceX, sourceY;
int destX, destY;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

deque<pair<int, int>> Q;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

void initData(){
	memset(MATRIX, 0, sizeof(MATRIX));
	Q.clear();
}

int BFS(int X, int Y){
	int result = 0;
	

}

int main(){
	initSet();
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		initData();
		cin >> N;
		cin >> sourceX >> sourceY;		
		cin >> destX >> destY;
		BFS(sourceX, sourceY);	
	}
}
