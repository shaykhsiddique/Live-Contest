#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define scs(x) scanf("%s",x)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
#define memc(x,y) memcpy(&x,&y,sizeof(x))
#define mems(x,y) memset(x,y,sizeof(x))
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define rep(i,v) for(int i=0;i<v;i++)
#define repe(i,v) for(int i=0;i<=v;i++)
#define Rep(i,x,v) for(int i=x;i<v;i++)
#define Repe(i,x,v) for(int i=x;i<=v;i++)
#define repv(i,x) for(auto i=x.begin();i!=x.end();i++)
#define reprv(i,x) for(auto i=x.rbegin();i!=x.rend();i++)
#define dbg(x) cout << #x << " : " << x << endl
#define pb push_back
#define bl putchar('\n')
#define gcc getchar()
#define pcc putchar
#define si size
#define fi first
#define se second
#define MAX 25
#define invalid(x,y) (x<0 or y<0 or x>=node_no or y>=node_no)
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
using namespace std;

char g[MAX][MAX];
int node_no,sx,sy;
bool vis[MAX][MAX];

int d1[]={0,0,1,-1};
int d2[]={1,-1,0,0};

bool bfs(){
    queue<ii>q;     // u,v
    queue<int>cost;
    mems(vis,0);
    q.push({sx,sy});
    cost.push(0);
    int u,v,x,y,cs;
    while(!q.empty()){
        u=q.front().fi;
        v=q.front().se;
        cs=cost.front();
//        cout<<u<<" "<<v<<" "<<cs<<endl;
        q.pop();
        cost.pop();
        rep(i,4){
            x=u+d1[i];
            y=v+d2[i];
            if(invalid(x,y)) continue;
            if(g[x][y]=='#' and cs<15) {
//                dbg(cs+1);
                return true;
            }
//            cout<<"    "<<x<<" "<<y<<endl;
            if(g[x][y]=='.') continue;
//            cout<<"      passed "<<endl;
            if(g[x][y]=='*' and cs<15){
                q.push({x,y});
                cost.push(cs+1);
            }
            if(g[x][y]=='$' and vis[x][y]==0){
                vis[x][y]=1;
                q.push({x,y});
                cost.push(0);
            }
        }
    }
    return false;
}

int main(){
//    fli();
    while(sc(node_no)==1){
        rep(i,node_no){
            scanf("%s",g[i]);
            rep(j,node_no){
                if(g[i][j]=='@') sx=i,sy=j;
            }
        }
        if(bfs()==1) puts("Yes");
        else puts("No");
    }
    return 0;
}
