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
bool vis[MAX][MAX];
char graph[MAX][MAX];
int r,c,w,fpx,fpy,spx,spy,dx,dy;
bool invalid(int x,int y){return (x<0 or x>=r or y<0 or y>=c);}

int d1[]={0,0,1,-1};
int d2[]={1,-1,0,0};

int mat[MAX][MAX];

int bfs(int x,int y,int step){
    memset(vis,0,sizeof(vis));
    memset(mat,0,sizeof(mat));
    priority_queue<pair<int,pair<int,int>>>q;
    int u,v;
    q.push({-step,{x,y}});
    bool flag;
//    cout<<" playing "<<step<<endl;
    while(!q.empty()){
        step=-q.top().first;
        u=q.top().second.first;
        v=q.top().second.second;
        q.pop();
//        cout<<"    in "<<u<<" "<<v<<endl;
        vis[u][v]=1;
        flag=true;
        for(int stt=1;stt<=step and flag;stt++){
            rep(i,4){
                x=u+d1[i]*stt;
                y=v+d2[i]*stt;
                if(invalid(x,y)) continue;
                if(graph[x][y]=='#'){
                    flag=false;
                    break;
                }
                if(vis[x][y]){
                    continue;
                }
                vis[x][y]=1;
                q.push({-step,{x,y}});
                mat[x][y]=step+2;
            }
        }
    }
    if(mat[dx][dy]==0){
        return INT_MAX;
    }else return mat[dx][dy];
}

int main(){
//    fli();
    int t,ans1,ans2;
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
                }else if(graph[i][j]=='D'){
                    dx=i;dy=j;
                }
            }
        }
        if(w==1){
            ans1=bfs(fpx,fpy,1);
            ans2=bfs(spx,spy,2);
            if(ans1==INT_MAX and ans2==INT_MAX) printf("IMPOSSIBLE\n");
            else if(ans1<ans2) puts("Saif");
            else puts("Sabi");
        }else{
            ans1=bfs(spx,spy,1);
            ans2=bfs(fpx,fpy,2);
            if(ans1==INT_MAX and ans2==INT_MAX) printf("IMPOSSIBLE\n");
            else if(ans1<ans2) puts("Sabi");
            else puts("Saif");
        }
    }
    return 0;
}

