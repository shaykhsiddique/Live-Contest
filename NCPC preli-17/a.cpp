#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,n,t,a,d,k,m,ans=0;
    double sum;
    scanf("%lld", &t);
    for(ll i=1;i<=t;i++)
    {
        ans = 0;
        scanf("%lld %lld %lld", &a, &d, &k);
        //cin>>a>>d>>k;
        sum = 0;
        sum= (k*(2*a+(k-1)*d))/2.0;
        scanf("%lld %lld %lld", &a, &d, &k);
        //cin>>a>>d>>k;
        sum+=  (k*(2*a+(k-1)*d))/2.0;
        ans = sum;
        printf("Case %lld: %lld\n", i, ans);
        //cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
