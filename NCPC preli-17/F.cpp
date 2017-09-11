#include<bits/stdc++.h>



#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d:\n", i)
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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define M 2000
using namespace std;
    //SHAYKH SIDDIQUE


int test,n;
ll num[M+5];

int main()
{
    sfi(test);

    for(int kk=1;kk<=test;kk++)
    {
        sfi(n);

        for(int i=0; i<n; i++)
        sfl(num[i]);

        ll ans;
        int k;
        ll x1,y1;
        sfi(k);

        pfc(kk);
        for(int i=0;i<k;i++)
        {
            ans=0;
            sfl(x1);
            for(int j=0;j<n;j++)
            {
                y1=num[j]%(x1+1);
                ans^=y1;
            }
            if(!ans)
                printf("Query %d: Lose\n",i+1);
            else
                printf("Query %d: Win\n",i+1);
        }
    }

    return 0;
}
