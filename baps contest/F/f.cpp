#include<bits/stdc++.h>
#define sf(n) scanf("%lld", &n)
#define sf2(x, y) scanf("%lld %lld", &x, &y);
#define pf(n) printf("%d", n)
#define pfn printf("%d\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
using namespace std;

int main(){
fli();
ll test, arr[205], a, b, dd, ee, ff;
sf(test);
for(ll i=1; i<=test; i++){
    ll n;
    sf(n);
    for(ll j=0; j<n; j++)
        sf(arr[j]);
    sort(arr, arr+n);
    sf2(a, b);
    ll c=0;
    for(ll l=0; l<n; l++){
        for(ll m=l; m<n; m++){
            for(ll p=m; p<n; p++){
                if(arr[l]+arr[m]+arr[p]>b)
                    continue;
                dd=a-(arr[l]+arr[m]+arr[p]);
                ee=lower_bound(arr+p, arr+n, dd)-arr;
                dd=b-(arr[l]+arr[m]+arr[p]);
                ff=upper_bound(arr+p, arr+n, dd)-arr;
                c+=(ff-ee);
            }
        }
    }
    printf("Case %lld: %lld\n", i, c);
}
return 0;
}
