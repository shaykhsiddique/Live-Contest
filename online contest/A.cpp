#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define F first
#define S second
#define M 1000010

ll odd[M+10], even[M+10];

void func()
{
    ll temp=0;
    for(ll i=1; i<M; i+=2)
    {
        temp+=(i*i);
        even[i+1]=temp;
    }

    temp=0;
    for(ll i=2; i<M; i+=2)
    {
        temp+=(i*i);
        odd[i+1]=temp;
    }
}

int main()
{
    func();
    ll n;
    double ans;
    while(sf("%lld", &n)==1 && n)
    {
        if(n%2==0)
        {
            ans=(even[n]*(ll)2);
            ans/=(n-1);
        }
        else
        {
            ans=(odd[n]*(ll)2);
            ans/=(n-1);
        }
        pf("%.6lf\n", sqrt(ans));
    }
    return 0;
}