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
fli();
int test;
sf(test);
vector<int>num;


int a[10005];
int b[10005];
    for(int i=1; i<=test; i++){
        int n, q;
         sf2(n, q);
        for(int j=0; j<n; j++){
            int l;sf(l);
            num.pb(l);
        }

          sort(num.begin(), num.end());
        int cont=0;
        for(int k=0; k<q; k++) {sf(a[k]);sf(b[k]);

    for(int j=num.size()-1; j>a[i]; j--)
        cont++;
    }
    cout<<cont<<endl;
    }

    return 0;
}
