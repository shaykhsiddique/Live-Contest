#include <bits/stdc++.h>

using namespace std;

#define N       105

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool visit[N];

int graph[N][N];

int n, m;

int DFS(int src)
{
    visit[src] = true;
    for(int i = 1; i <= n; i++)
    {
        if(graph[src][i] && visit[i] == false)
            DFS(i);
    }
}

int main()
{
    int t, i, j ,caseNo = 1, u, v, cnt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        cnt = 0;
        memset(graph, 0, sizeof(graph));
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        for(i = 1; i <= n; i++)
        {
            if(visit[i] == false)
            {
                DFS(i);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }


    return 0;
}
