#include<bits/stdc++.h>

#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
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
#define find puts("I am here")
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,x,n) for(int i=x;i<n;i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 109
using namespace std;

              // Shaykh Siddique
bool vis[3][MAX][MAX];
char graph[MAX][MAX];
int r,c,w,fpx,fpy,spx,spy;
bool invalid(int x,int y){return (x<0 or x>=r or y<0 or y>=c);}

int d1[]={0,0,1,-1};
int d2[]={1,-1,0,0};

const char* bfs(){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>>q;
    queue<int>p,s;
    int u,v,x,y,pl,st;
    p.push(w);
    p.push(3-w);
    if(w==1){
        q.push({fpx,fpy});
        q.push({spx,spy});
    }else{
        q.push({spx,spy});
        q.push({fpx,fpy});
    }
    s.push(1);s.push(2);
    while(!q.empty()){
        u=q.front().first;
        v=q.front().second;
        q.pop();
        pl=p.front();
        p.pop();
        st=s.front();
        s.pop();
        vis[pl][u][v]=1;
//        if(pl==1) cout<<" 1 is in " <<u<<" "<<v<<endl;
//        if(pl==2) cout<<" 2 is in " <<u<<" "<<v<<endl;
        rep(ii,4){
            for(int stt=1;stt<=st;stt++){
                x=u+d1[ii]*stt;
                y=v+d2[ii]*stt;
                if(invalid(x,y)) continue;
                if(graph[x][y]=='#') break;
                if(vis[pl][x][y]) continue;
                if(graph[x][y]=='D') return (pl==1)?"Saif":"Sabi";
                vis[pl][x][y]=1;
                q.push({x,y});
                p.push(pl);
                s.push(st+1);
            }
        }
    }
    return "IMPOSSIBLE";
}

int main(){
//    fli();
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;cc++){
        pfc(cc);
        scanf("%d%d%d",&r,&c,&w);
        rep(i,r){
            scanf("%s",graph[i]);
            rep(j,c){
                if(graph[i][j]=='1'){
                    fpx=i;fpy=j;
                }else if(graph[i][j]=='2'){
                    spx=i;spy=j;
                }
            }
        }
        printf("%s\n",bfs());
    }
    return 0;
}

