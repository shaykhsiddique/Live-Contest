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
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

// Shaykh Siddique




int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();

    //double ans = 1.0/6227020800;
    //printf("%.12f", ans);
    int test;
    ll n;
    sfi(test);
    for(int i=1; i<=test; i++)
    {
        sfl(n);
        switch(n){
        case 1:
            puts("1.0000000000");
            break;
        case 2:
            puts("0.5000000000");
            break;
        case 3:
            puts("0.1666666666");
            break;
        case 4:
            puts("0.0416666666");
            break;
        case 5:
            puts("0.0083333333");
            break;
        case 6:
            puts("0.0013888888");
            break;
        case 7:
            puts("0.0001984126");
            break;
        case 8:
            puts("0.0000248015");
            break;
        case 9:
            puts("0.0000027557");
            break;
        case 10:
            puts("0.0000002755");
            break;
        case 11:
            puts("0.0000000250");
            break;
        case 12:
            puts("0.0000000020");
            break;
        case 13:
            puts("0.0000000001");
            break;
        default:
            puts("0.0000000000");
            break;
        }
    }

    return 0;
}
