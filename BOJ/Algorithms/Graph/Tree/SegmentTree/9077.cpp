#include <iostream>
#define MAX 1000001
using namespace std;

int arr_x[MAX];
int arr_y[MAX];

int tree_x[MAX*4];
int tree_y[MAX*4];

void initSet(){
    fill_n(arr_x, MAX, 0);
    fill_n(arr_y, MAX, 0);
    fill_n(tree_x, MAX, 0);
    fill_n(tree_y, MAX, 0);
}

int init(int start, int end, int node, int * arr, int * tree){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2, arr, tree) + init(mid + 1, end, node * 2 + 1, arr, tree);
}

int sum(int start, int end, int node, int left, int right, int * tree){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right, tree) + sum(mid + 1, end, node * 2 + 1, left, right, tree);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCase; cin >> testCase;
    while(testCase--){
        initSet();
        int N; cin >> N;
        int maxLenX = -1;
        int maxLenY = -1;
        int answer = -1;
        int X, Y;
        for(int i = 0; i < N; i++){
            int x, y; cin >> x >> y;
            arr_x[x] = 1;
            arr_y[y] = 1;
            maxLenX = max(maxLenX, x);
            maxLenY = max(maxLenY, y);
        }
        init(0, maxLenX, 1, arr_x, tree_x);
        init(0, maxLenY, 1, arr_y, tree_y);
        for(int i = 0; i + 10 < maxLenX; i++){
            for(int j = 0; j + 10 < maxLenY; j++){
                int xSum = sum(0, maxLenX, 1, 0, i + 10, tree_x);
                int ySum = sum(0, maxLenY, 1, 0, j + 10, tree_y);
                //answer = max(answer, xSum + ySum);
                if(answer < xSum + ySum){
                    answer = xSum + ySum;
                    X = i;
                    Y = j;
                }
            }
        }
        cout << answer << '\n';
    }
}