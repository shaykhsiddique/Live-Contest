
#include<bits/stdc++.h>
#define MAXN 111111
using namespace std;
vector<int> G[MAXN];

int t,ca,n,m,x;
int dn[MAXN];
int dp[MAXN];

int f(int u){
    if(dn[u]==ca)return dp[u];
    dn[u] = ca;
    for(int i =0  ,v,len = G[u].size();i<len;i++){
        v = G[u][i];
        int tmp = f(v);
        if(tmp == 0){
            return dp[u] = 1;
        }
    }
    return dp[u] = 0;
}



int main(){
   // freopen("pin.txt","r",stdin);
    memset(dn,0,sizeof(dn));
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++){
        scanf("%d %d %d",&n,&m,&x);
        for(int i = 0 ; i <=n;i++){
            G[i].clear();
        }
        for(int i = 0,u,v;i<m;i++){
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
        }
        if(f(x)){
            printf("Case %d: Yes\n",ca);
        }
        else{
            printf("Case %d: No\n",ca);
        }
    }

    return 0;
}

