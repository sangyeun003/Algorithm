#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <queue>

using namespace std;

vector<int> map[100001];
queue<int>  q;
int         visited[100001];

void    bfs(int start)
{
    int cnt;

    cnt = 1;
    visited[start] = cnt;
    cnt++;
    q.push(start);
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        for (int i = 0; i < map[start].size(); i++)
        {
            if (visited[map[start][i]] == 0)
            {
                visited[map[start][i]] = cnt;
                cnt++;
                q.push(map[start][i]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    int r;

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(map[i].begin(), map[i].end());
    bfs(r);
    for (int i = 1; i <= n; i++)
        cout << visited[i] << "\n";
    return (0);
}
