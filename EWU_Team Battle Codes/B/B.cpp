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
#define what_is(x) cerr << #x << " : " << x << endl
#define pb push_back
#define bl putchar('\n')
#define gcc getchar()
#define pcc putchar
#define si size
#define fi first
#define se second
#define MAX 100000
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
using namespace std;

map<int,int>mp;

int main(){
//    fli();
    int n,m,a,b;
    sc(n);
    while(n--){
        sc(a);
        mp[a]++;
    }
    sc(m);
    while(m--){
        sc(b);
        if(mp[b]>1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}





