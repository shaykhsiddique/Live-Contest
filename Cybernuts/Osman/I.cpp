#include<bits/stdc++.h>

using namespace std;
#define pause system("pause");
#define mod 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size()  )
#define sqr(x) ( (x) * (x) )
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
#define pf printf
#define reset(x,v)  memset (x,v,sizeof(x) ) ;
#define what_is(x) cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef long long vlong;


ll mod_v(ll x)
{
    return x%mod;
}

inline vlong bigmod(vlong a, vlong p, vlong m)
{
    vlong res = 1%m, x = a%m;

    while(p)
    {
        if(p&1) res = (res*x) % m;
        x = (x*x)%m; p >>= 1;
    }
    return res;
}



int n,m;
int a[100005];
int b[100005];

ll dp[100004][3] ;

ll re(int pos,int tp)
{
    if(pos==m)
    {

        if(tp==1 )
            return (n-a[pos-1] +1) ;

        return 1;
    }

    ll &res=dp[pos][tp];

    if(res!=-1) return res;

    res=0;

    if(b[pos]==0)
    {
        if(tp==2)
        {
                res=mod_v(res+   re(pos+1,0  )  );
        }
        else if(tp==1)
        {
            if((a[pos]- (pos==0?0:a[pos-1]  )- 1  ) >0 )
                res=mod_v(res+ re(pos+1,0) );
            res=mod_v(res+ re(pos+1,0) );
        }
        else
        {
            res=mod_v(res+ re(pos+1,0) );
        }

    }
    else if(b[pos]==1 )
    {
        if(tp==1)
        {
            if((a[pos]- (pos==0?0:a[pos-1]  )- 1  )>0 )
                res=mod_v(res+ (bigmod(2LL,(a[pos]- (pos==0?0:a[pos-1]  )- 1),mod  ) ) *  re(pos+1,0  )  );

           // res=mod_v(res+   re(pos+1,1  )  );
        }
        else if(tp==2)
        {
            res=mod_v(res+   re(pos+1,1  )  );
            // edit need
        }
        else if(tp==0)
        {
            if(((a[pos]- (pos==0?0:a[pos-1]  ) -1 )  >0 ) )
            {
                res=mod_v(res+   re(pos+1,0  )  );
            }

            else
                res=mod_v(res+   re(pos+1,1  )  );
        }
    }
    else
    {
                res=mod_v(res+re(pos+1,2)  ) ;

    }

    return res;
}

int main()
{
    #ifdef kimbbakar
    freopen("in.txt","r",stdin );

    #endif // kimbbakar

    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(int i=0;i<m;i++)
            scanf("%d",&a[i] );


        for(int i=0;i<m;i++)
            scanf("%d",&b[i] );

        reset(dp,-1);

        pf("%lld\n",re(0,0) );
    }


    return 0;
}
