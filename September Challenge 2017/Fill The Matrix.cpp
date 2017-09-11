#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:                |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define fi first
#define se second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
const long long inf = 1000000000LL;
const int i32_max = 2147483645;
using namespace std;




#define PAIR pair<int, int>
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};

int dir_x1[] = {-1, -1, 1, 1};
int dir_y1[] = {-1, 1, 1, -1};


// Code starts from here

int grid[1000][1000];
bool visit[1000][1000];
int n;

void repair_grid(int n){
    rep(i, 0, n+2){
        rep(j, 0, n+2){
            grid[i][j]=5;
            visit[i][j]=false;
        }
    }
}




bool bfs(int src_i, int src_j){
    queue<PAIR>Q;
    Q.push({src_i, src_j});
    visit[src_i][src_j]=true;
    while(!Q.empty()){
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        rep(cc, 0, 4){
            int i= x + dir_x[cc];
            int j= y + dir_y[cc];
            if(i>0 and i<=n and j>0 and j<=n and !visit[i][j]){
                visit[i][j]=true;
                if(grid[i][j]== false)
                    return false;
                Q.push({i, j});
            }

        }
    }
    return true;
}







int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, q, u, v, i_i, j_j, kkk;
    bool val;
    bool check;
    sfi(test);
    repe(cc, 1, test){
//        memset(grid, 0, sizeof(grid));
        check=false;
        sfi2(n, q);
        repair_grid(n+2);
        rep(i, 0, q){
            sfi2(u, v); sfi(kkk);
            if(kkk==1){
                val=true;
            }else{
                val=false;
            }
            grid[u][v]=val;
            if(val==0){
                check=true;
                i_i = u;
                j_j= v;
            }
        }
//        print_grid(n);bl;bl;
        bool ans = bfs(i_i, j_j);
        if(!check) pf("no\n");
        else if(ans) pf("yes\n");
        else pf("no\n");


    }
    return 0;
}


