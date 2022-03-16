#include <iostream>
#define MAX 100001
#define MAXVALUE 1000000001
using namespace std;
long long maxTree[4 * MAX];
long long minTree[4 * MAX];
long long arr[MAX];

int init(int start, int end, int node, bool maximum)
{
    if (start == end)
    {
        if (maximum)
            return maxTree[node] = arr[start];
        else
            return minTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    if (maximum)
        return maxTree[node] = max(init(start, mid, 2 * node, maximum), init(mid + 1, end, 2 * node + 1, maximum));
    return minTree[node] = min(init(start, mid, 2 * node, maximum), init(mid + 1, end, 2 * node + 1, maximum));
}

int findVal(int start, int end, int left, int right, int node, bool maximum)
{
    if (left > end || right < start)
    {
        if (maximum)
            return -MAXVALUE;
        return MAXVALUE;
    }
    if (left <= start && end <= right)
    {
        if (maximum)
            return maxTree[node];
        else
            return minTree[node];
    }
    int mid = (start + end)/2;
    if (maximum)
        return max(findVal(start, mid, left, right, node * 2, maximum), findVal(mid + 1, end, left, right, node * 2 + 1, maximum));
    return min(findVal(start, mid, left, right, node * 2, maximum), findVal(mid + 1, end, left, right, node * 2 + 1, maximum));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N * 4; i++)
        minTree[i] = MAX;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    init(0, N - 1, 1, true);
    init(0, N - 1, 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int right = max(a, b);
        int left = min(a, b);
        cout << findVal(0, N - 1, left - 1, right - 1, 1, false) << " " << findVal(0, N - 1, left - 1, right - 1, 1, true) << '\n';
    }
    return 0;
}