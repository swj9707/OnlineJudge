#include <iostream>
#include <deque>
#define MAX 101

using namespace std;

typedef struct point{
    int Y;
    int X;
    int H;
} point;

int M, N, H;
int MATRIX[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
deque<point> DQ;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

int main(){

}