#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printData(T a){
    for(auto i : a){
        cout << i << " ";
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int answer = 0;
        int N;
        cin >> N;
        int *Map;
        Map = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) cin >> Map[i];
        vector<vector<int>> routeData;
        for(int i = 0; i < N; i++){
            int dest = -1;
            int k;
            if(i + 15 < N) k = i + 15;
            else k = N - 1;
            for(int j = k; j > i; j--){
                if(Map[j] == 3){
                    dest = j;
                    break;
                }
            }
            if(dest == -1) break;
            vector<int> tmp;
            for(int j = i; j <= dest; j++) tmp.push_back(Map[j]);
            routeData.push_back(tmp);
            cout << "dest : " << dest << "\n";
            i = dest;
        }
        for(auto route : routeData){//마지막 인덱스 = 목적지
            for(int i = 0; i < route.size(); i++){
                
            }
        }

        cout << "#" << caseNum << " " << answer << '\n';
        free(Map);
    }
}