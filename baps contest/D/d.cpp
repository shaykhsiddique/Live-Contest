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
using namespace std;

int main(){
fli();
int test;
sf(test);
for(int i=1; i<=test; i++){
    int n, m, num1, num2, nmax, mmax;
    sf2(n, m);
    ll sum=0;
    for(int j=0; j<n; j++){
        sf(num1);
        sum+=num1;
        if(j==n-1)
            nmax=num1;
    }
    for(int j=0; j<m; j++){
        sf(num2);
        sum+=num2;
        if(j==m-1)
            mmax=num2;
    }
    printf("Case %d: %lld\n", i, (sum-max(nmax, mmax)));
}
return 0;
}
