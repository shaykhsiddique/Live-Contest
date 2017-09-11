#include <bits/stdc++.h>
using namespace std;
#define N       105


int graph[N][N];
vector <int> A[N],B[N],x, y;
stack <int>st;
bool mark[N];
bool visit[N];

int n, m;

void dfs1(int u)
{
    if(visit[u])
        return;
    visit[u] = true;
    for(int i = 0; i < A[u].size(); i++)
    {
        int v = A[u][i];
        dfs1(v);
    }
    st.push(u);
}

void dfs2(int u)
{
    if(visit[u] == true)
        return;
    visit[u] = true;
    for(int i = 0; i <B[u].size(); i++)
    {
        int v = B[u][i];
        dfs2(v);
    }
    x.push_back(u);
}


int main()
{
    int t, i, j ,caseNo = 1, z=0,u, v, cnt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        cnt = 0;z++;
        //memset(graph, 0, sizeof(graph));
        for(i = 0; i <= n; i++)
        {
            A[i].clear();B[i].clear();
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            A[u].push_back(v);
            B[v].push_back(u);
        }
        memset(visit, false, sizeof(visit));
        for(i = 1; i <= n; i++)
        {
            if(visit[i] == false)
            {
                dfs1(i);
            }
        }
        memset(visit, false, sizeof(visit));
        while(!st.empty())
        {
            int p;
            p = st.top();
            st.pop();
            if(visit[p] == false)
            {
                x.clear();
                dfs2(p);
                cnt++;
                if(x.size() > 1)
                    cnt--;
            }
        }
        //for(j = 0; j <x.size(); j++)
        //printf("%d ", x[i]);

        printf("Case %d: %d\n",z, cnt);
    }


    return 0;
}

