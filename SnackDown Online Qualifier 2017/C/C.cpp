#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:                |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d:\n", i)
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
#define fi first
#define se second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Code starts from here

ll arr[100005];
ll sum[100005];

ll bs2(ll *ar, ll min, ll f, ll l, ll abslast){
            //in 1st case f is the last snake which qualifies
            if((f== l) && (( min * (abslast - f + 1) - (sum[abslast] - sum[f-1])) <= f)) return f;
            else if(f == l) return -10;//no extra snake qualifies
            ll mid = (f + l)/2;
            if((min * (abslast - mid + 1)-(sum[abslast] - sum[mid-1])) > mid){
                //search in right half
                return bs2(ar,min,mid+1,l,abslast);
            }//sum(of length required) from mid to end both inclusive
            else{
                //search in left including mid
                return bs2(ar,min,f,mid,abslast);
            }
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, n, q;
    ll num, qr;
    sfi(test);
    repe(cc, 1, test){
        memset(sum, 0, sizeof(sum));
        sfi2(n, q);
        rep(i, 0, n){
            sfl(arr[i]);
        }
        sort(arr, arr+n);
        bool check=false;
        ll add=0;
        for(int i=0; i<n; i++){
            add+=arr[i];
            sum[i]=add;
        }
        ll ans;
        rep(i, 0, q){
            sfl(qr);
            ll dir=lower_bound(arr, arr+n, qr)-arr;
            ans=n-dir;
            ll added=bs2(arr, qr, 0, dir-1, dir-1);
            if(added>0){
                ans=(n-added);
            }
            pf("%lld\n", ans);
        }
    }

    return 0;
}
