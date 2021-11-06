#include <iostream>
#include <deque>
using namespace std;

bool visit[2][100001];
int N, K;

void BFS()
{
    int count = 1;
    deque<pair<int, int>> DQ;
    DQ.push_back({0, 1});
    visit[0][1] = true;
    while (!DQ.empty())
    {
        int line = DQ.front().first;
        int index = DQ.front().second;
        DQ.pop_front();
        if (index > N)
        {
            cout << "1\n";
            return;
        }
        if(!visit[line][index+1]){
            DQ.push_back({line, index + 1});
            visit[line][index + 1] = true;
        }
        if(index - 1 > 0 && !visit[line][index-1]){
            DQ.push_back({line, index - 1});
            visit[line][index - 1] = true;
        }
        if(line == 0) line = 1;
        else line = 0;
        if(!visit[line][index + K]){
            DQ.push_back({line, index + K});
            visit[line][index + K] = true;
        }
        visit[0][count] = true;
        visit[1][count] = true;
        count++;
    }
    cout << "0\n";
    return;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < 2; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++)
        {
            if (tmp[j] == '0') visit[i][j] = true;
        }
    }
    BFS();
}