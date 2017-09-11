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


int main(){
//fli();
//flo();
int test, a;
ll n;
sfi(test);
ll rid, pid;
for(int i=0; i<test; i++){
    sfl(n);
    map<ll, ll>str;
        for(ll j=0; j<n; j++){
        sfi(a);
        if(a==1){

            sfl2(pid, rid);
        if(!str[rid]){
            printf("Y\n");
            str[rid]=pid;
        }
        else
            printf("N\n");
        }
        else{
            sfl(rid);
            if(!str[rid])
                printf("F\n");
            else{
                printf("%lld\n", str[rid]);
                str[rid]=0;
            }
        }
    }
}
return 0;
}
