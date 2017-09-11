#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn(n) printf("%d\n", n)
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
#define mem(n, k) memset(n, k, sizeof(n))
#define MOD 100000007
using namespace std;

int main(){
//fli();
    int test;
    sf(test);
    loope(1, test){
        int a, b;
        sf2(a, b);
        int k=a+b;
        int j=max(a, b)-min(a, b);
        printf("Case %d: %d%d\n", i, k, j);
    }

    return 0;
}
