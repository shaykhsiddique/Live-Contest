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
#define ll_MAX 9223372035
using namespace std;

              // Code starts from here

ll arr[1000010];
ll arr1[1000010];
ll arr2[1000010];


ll max_sub_arr(int n){
    arr1[0]=arr[0];
    ll maxi=arr[0];
    rep(i, 1, n){
        arr1[i]=max(arr1[i-1]+arr[i], arr[i]);
        maxi=max(maxi, arr1[i]);
    }
    arr2[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
        arr2[i]=max(arr2[i+1]+arr[i], arr[i]);

    rep(i, 1, n-1)
        maxi=max(maxi, arr1[i-1]+arr2[i+1]);

    return maxi;
}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, n;
    ll sum;
    sfi(test);
    while(test--){
        sfi(n);
        ll mex=0;
        int ind=-1;
        rep(i, 0, n){
            sfl(arr[i]);
//            if(arr[i]<0){
//                if(abs(arr[i])>mex){
//                    mex=arr[i];
//                    ind=i;
//                }
//            }
        }
        pf("%lld\n", max_sub_arr(n));
    }

    return 0;
}

