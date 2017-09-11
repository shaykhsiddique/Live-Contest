#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define F first
#define S second
#define M 80

struct st
{
    int x, y;
};

int main()
{
    int n, mini=1000000010, maxi=0;

    sf("%d", &n);
    vector<st>vv(n);

    for(int i=0; i<n; i++)
    {
        sf("%d %d", &vv[i].x, &vv[i].y);
        mini=min(mini, vv[i].x);
        maxi=max(maxi, vv[i].y);
    }

    for(int i=0; i<n; i++)
    {
        if(vv[i].x==mini && vv[i].y==maxi)
        {
            pf("%d\n", i+1);
            return 0;
        }
    }

    pf("-1\n");

    return 0;
}