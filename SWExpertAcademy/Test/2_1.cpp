#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//세트가 되는 조건은 고른 3장의 카드가 지닌 4가지 속성이 각각 모두 같거나 모두 달라야 한다.
//한 조건이 모두 같거나 한 조건이 모두 다르거나 ㅇㅇ
//ex) 모양이 같고 색이 전부 다른데 한놈만 채워져있고 나머지가 뻥뚫리면 ㅅㄱㄹ

/*
첫 번째 문자 : 도형의 수 / 1,2,3 중 하나의 문자로 입력

두 번째 문자 : 도형의 색 / R(빨간색),G(초록색), P(보라색) 중 하나의 문자로 입력

세 번째 문자 : 도형의 모양 / E(타원),D(다이아몬드),T(구불구불한 모양) 중 하나의 문자로 입력

네 번째 문자 : 도형의 음영 / F(모두 색칠),S(줄무늬),W(테두리만 색칠) 중 하나의 문자로 입력

ex) 2GEF : 초록색이 모두 칠해진 타원이 2개 그려져 있는 카드
3PTS : 보라색이 줄무늬로 칠해진 구불구불한 도형이 3개 그려진 카드
*/

typedef struct node{
    int amount;
    char color;
    char shape;
    char shadow;
} node;

bool compare(const node & node1, const node & node2){
    return node1.amount < node2.amount;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1 ; t <= T; t++){
        int answer = 0;
        int N;
        cin >> N;
        vector<node> vec;
        for(int i = 0; i < N; i++){
            string tmp;
            cin >> tmp;
            node tmpNode;
            tmpNode.amount = tmp[0] - '0';
            tmpNode.color = tmp[1];
            tmpNode.shape = tmp[2];
            tmpNode.shadow = tmp[3];
            vec.push_back(tmpNode);
        }
        sort(vec.begin(), vec.end(), compare);
        for(int i = 0; i < N; i++){
            cout << i << " node : " << vec[i].amount << vec[i].color << vec[i].shape << vec[i].shadow << '\n';
        }
        cout << "#" <<t << " " << answer <<'\n';
    }
    return 0;
}