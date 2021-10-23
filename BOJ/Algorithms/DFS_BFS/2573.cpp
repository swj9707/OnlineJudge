#include <iostream>
<<<<<<< HEAD

using namespace std;

int main(){
        
=======
#include <deque>
#include <vector>
#include <cstring>
#define MAX 300
using namespace std;

int MATRIX[MAX][MAX];
bool Visit[MAX][MAX];
vector<int> V;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

void printMatrix(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cout << MATRIX[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }

>>>>>>> b011093d182cda905bb85bffaf306ac5016a4695
}