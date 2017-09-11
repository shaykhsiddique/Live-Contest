#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
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
#define MOD 1000000007
using namespace std;

int main(){
fli();
int test;
sf(test);
for(int i=1; i<=test; i++){
    int m, k;
    sf2(m, k);
    ll ans=k*(k-1);
    for(int j=0; j<m-1; j++){
        ans=((ans%MOD)*((k-2)*(k-2)+(k-1))%MOD)%MOD;
    }
    cout<<ans<<endl;
}
return 0;
}
