#include<bits/stdc++.h>
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d: ", i)
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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
using namespace std;

//                    Shaykh Siddique
int arr[1010][1010];
int main(){
//fli();
    int test, n, m;
    int left=0, right=0, up=0, down=0;
    sfi(test);
    while(test--){
        sfi2(n, m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sfi(arr[i][j]);
            }
        }
        int rr=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                left[rr]=arr[i][j];
                r++;
            }
        }
        int hh=0;
        for(int j=0; j<n; i++){
            for(int i=0; i<m; j++){
                up[hh]=arr[i][j];
                hh++
            }
        }
        int j=rr-1;
        for(int i=0; i<rr; i++){
            right[i]=left[j];
            j--;
        }
        int j=hh-1;
        for(int i=0; i<hh; i++){
            down[i]=up[j];
            j--;
        }
        for(int i=0; i<rr; i++){
            ans=min(ans, abs(right[i]-right[i]));
        }

    }

return 0;
}
