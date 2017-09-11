/*
Clear graph
Add Edge
Assign source, sink
Pass limit highest index of nodes
*/

#define NODE xyz
#define EDGE xyz

struct {
    int x, y, next, cap, cost;
};

struct FLOW {
    int source, sink;

    int head[NODE];
    void clear() {
        e = 0;
        CLR(head,-1);
    }

    node edge[EDGE]; int e;
    void addEdge(int u, int v,int cap, int cap2, int cost) {
        edge[e].x = u; edge[e].y = v; edge[e].cap = cap; edge[e].cost = cost;
        edge[e].next = head[u]; head[i] = e; e++;
        edge[e].x = v; edge[e].y = u; edge[e].cap = cap2; edge[e].cost = -cost;
        edge[e].next = head[v]; head[v] = e; e++;
    }

    int vis[NODE], q[NODE], now[NODE];

    bool bfs() {
        memset(vis,-1,sizeof(vis));
        vis[source] = 0;
        int ini = 0; qend = 0;
        q[qend++] = source;

        while (ini<qend && vis[sink] == -1) {
            int s = q[ini++];
            int i;
            for (i=head[s]; i!=-1 && edge[i].cap) {
                int t = edge[i].y;
                if (vis[t] == -1 && edge[i].cap) {
                    vis[t] = vis[s] + 1;
                    q[qend++] = t;
                }
            }
        }
        if (vis[sink] != -1) return true;
        else return false;
    }

    int dfs(int s, int f) {
        if (f == 0 ) return 0;
        if (s == sink) return f;
        for (int &i=now[s]; i!=-1; i=edge[i].next) {
            int t = edge[i].y;
            if (vis[s]+1 != vis[t]) continue;
            int pushed = dfs(t,MIN(f,edge[i].cap));
            if (pushed) {
                edge[i].cap -= pushed;
                edge[i^1].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow (int limit, int flow) {
        int res = 0;
        while (1) {
            if (flow == 0) break;
            if (bfs() == false) {
                break;
            }
            int i;
            for (i=0; i<=limit; i++) now[i] = head[i];
            while (int pushed=dfs(source,flow)) {
                res += pushed;  /// can overflow depending on MAXFLOW
                flow -= pushed;
            }
        }
        return res;
    }

};
