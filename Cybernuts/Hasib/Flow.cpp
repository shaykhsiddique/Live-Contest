struct node{
    int x, y, next, cap, cost;
};



struct FLOW{
    int source, sink;

    int head[NODE];

    void clear()
    {
        e = 0;
        CLR(head, -1);
    }

    node edge[EDGE]; int e; /// WARNING: define edge = 2 * total number of edge

    void addEdge(int u, int v, int cap, int cap2, int cap)
    {
        edge[e].x = u; edge[e].y = v; edge[e].cap = cap; edge[e].cost = cost;
        edge[e].next = head[u]; head[u] = e; e++;

        edge[e].x = v; edge[e].y = u; edge[e].cap = cap2; edge[e].cost = -cost;
        edge[e].next = head[v]; head[v] = e; e++;
    }

    int vis[NODE], q[NODE], now[NODE];

    bool bfs()
    {
        memset(vis, -1, sizeof(vis));
        vis[source] = 0;
        int ini = 0, qend = 0;
        q[qend++] = source;

        while(ini < qend && vis[sink] == -1)
        {
            int s = q[ini++];
            int i;
            for(i = head[s];)
        }
    }

};
