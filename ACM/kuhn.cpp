struct KUHN {
    int left[NODE], right[NODE], vis[NODE], cc;
    vector <int> adj[NODE];

    KUHN(): cc(1) {}

    void clear(int n) {
        FOR(i,0,n) adj[i].clear();
    }

    bool tryK(int v) {
        if (vis[v] == cc) {
            return false;
        }
        vis[v] = cc;
        for (int i=0; i<SZ(adj[v]); i++) {
            int t = adj[v][i];
            if (right[t] == -1) {
                right[t] = v;
                left[v] = t;
                return true;
            }
        }
        for (int i=0; i<SZ(adj[v]); i++) {
            int t=adj[v][i];
            if (tryK(right[t])){
                right[t] = v; left[v] = t;
                return true;
            }
        }
        return false;
    }

    int match(int n) {
        int res = 0;
        bool done;
        CLR(left,-1); CLR(right,-1);
        do {
            done = true; cc++;
            FOR(i,0,n) {
                if (left[i] == -1 && tryK(i)) {
                    done = false;
                }
            }
        } while (!done);
        for(i,0,n) res += (left[i]!=-1);
        return res;
    }
};
