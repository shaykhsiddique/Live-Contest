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
const long long inf = 1000000000LL;
const int i32_max = 2147483645;
using namespace std;




#define PAIR pair<int, int>
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};
// Code starts from here

int n;
ll arr[100005], cum[100005];

inline ll prefix_sum(int i){
    return cum[i];
}

ll suffix_sum(int i){
    if(i)
        return (cum[n-1]-cum[i-1]);
    else
        return cum[n-1];
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test;
    sfi(test);
    repe(cc, 1, test){
        sfi(n);
        rep(i, 0, n){
            sfl(arr[i]);
            if(!i)
                cum[i]=arr[i];
            else
                cum[i]=arr[i]+cum[i-1];
        }
        ll mini= inf;
        int ind=0;
        rep(i, 0, n){
            if(suffix_sum(i)+prefix_sum(i)<mini){
                mini=suffix_sum(i)+prefix_sum(i);
                ind =i;
            }
        }
        pfn(ind+1);
    }
    return 0;
}
