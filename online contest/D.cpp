#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define F first
#define S second
#define M 10000010

vector<ll>prime;
bitset<M+10>arr;

void sieve()
{
    for(ll i=2; i<M; i++)
    {
        if(arr[i]==0)
        {
            prime.pb(i);
            for(ll j=i*2; j<M; j+=i)
            {
                arr[j]=1;
            }
        }
    }
}

struct st
{
    ll a, b;
};

st func(ll num)
{
    st temp;
    temp.a=1;
    temp.b=1;
    ll cnt=0;
    for(ll i=0; prime[i]*prime[i]<=num && i<prime.size(); i++)
    {
        if(num%prime[i]==0)
        {
            cnt=0;
            while(num%prime[i]==0)
            {
                cnt++;
                num/=prime[i];
                if(cnt%2==0)
                {
                    temp.a*=prime[i];
                    cnt=0;
                }
            }

            if(cnt)
            {
                temp.b*=prime[i];
            }
        }
    }

    cnt=sqrt(num);
    if(cnt*cnt==num)
    {
        temp.a*=cnt;
    }
    else
    {
        temp.b*=num;
    }

    return temp;
}

int main()
{
    st ans;
    ll num;

    sieve();

    while(sf("%lld", &num)==1)
    {
        if(num==-1)
        {
            break;
        }
        ans=func(num);
        pf("%lld %lld\n", ans.a, ans.b);
    }

    return 0;
}
