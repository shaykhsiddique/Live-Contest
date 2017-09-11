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
#define MAX 10010
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
#define mo 1000000007
using namespace std;

vector<vector<int>>dp(1001);

int main(){
    fli();
    int t,r,c;
    r=10002;
    c=10002;
    dp.pb(vector<ll>());

    Repe(i,1,r) dp[i].pb(0),dp[i].pb(1);
    Repe(i,2,r){
        Repe(j,2,i){
            dp[i].pb(0);
            if(i==j){
                dp[i][j]=dp[i][j-1]*2;
                if(dp[i][j]>=mo)
                    dp[i][j]%=mo;
            }else{
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                if(dp[i][j]>=mo)
                    dp[i][j]%=mo;
            }
        }
    }
    sc(t);
    while(t--){
        sc2(r,c);
        if(c>r) swap(r,c);
//        rep(i,r+10){
//            dp.pb(vector<ll>(c+10));
//        }
//        cout<<dp.si()<<endl;
//        cout<<dp[0].si()<<endl;
        printf("%lld\n",dp[r][c]);
    }
    return 0;
}





