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

ll mod_v(ll x)
{
    return x%mod;
}
class nod
{
public:
    long long ara[3][3];

    nod()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ara[i][j]=0;

        ara[0][0]=ara[0][1]=ara[1][0]=ara[2][0]=ara[2][2]=1;
    }

    nod(int v)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ara[i][j]=0;

     //   ara[0][0]=ara[1][1]=ara[2][2]=1 ;
    }
};

nod mul(nod a,nod b)
{
    nod res = nod(0);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res.ara[i][j]=0;

            for(int k=0;k<3;k++)
            {
                res.ara[i][j]=mod_v(res.ara[i][j]+ a.ara[i][k]*b.ara[k][j]  ) ;
            }
        }
    }

    return res;
}

inline nod bigmod(nod a, ll p)
{
    nod res =nod();
    nod x = a ;

    while(p)
    {
        if(p&1) res = mul(res,x);
        x = mul(x, x); p >>= 1;
    }
  what_is(res.ara[2][0] )
    what_is(res.ara[2][2] )



    return res;
}


int main()
{
    #ifdef kimbbakar
    freopen("in.txt","r",stdin );

    #endif // kimbbakar

    nod res=bigmod(nod(),3-1 ) ;

    pf("%lld\n",res.ara[2][0]+res.ara[2][2]  ) ;


    return 0;
}
