#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
    |------------------------------------------------------------------|
    |                                                                  |
    |           â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��                  |
    |           â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��                  |
    |           â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��â�� â��â��â��â��â�� â��â��â��â��â��                  |
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

struct point {
    ll x, y;
};

char is_parallal(point h1, point h2, point t1, point t2){
    if(h1.x==t1.x and h2.x==t2.x) return 'X';
    else if(h1.y==t1.y and h2.y==t2.y) return 'Y';
    else return 'P';
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test;
    point h1, h2, t1, t2;
    sfi(test);
    while(test--){
        bool connected=false;
        sfl2(h1.x, h1.y);sfl2(t1.x, t1.y);
        sfl2(h2.x, h2.y);sfl2(t2.x, t2.y);
        if(is_parallal(h1, h2, t1, t2)=='Y' and h1.y==h2.y and h1.y==t1.y and h1.y==t2.y){
            if(h1.x>=h2.x and t1.x<=h2.x)
                connected=true;
            else if(h1.x>=t2.x and t1.x<=t2.x)
                connected=true;
            else if(h1.x<=h2.x and t1.x>=h2.x)
                connected=true;
            else if(h1.x<=t2.x and t1.x>=t2.x)
                connected=true;
            else if(h1.x<=h2.x and t1.x>=t2.x)
                connected=true;
            else if(h1.x>=h2.x and t1.x<=t2.x)
                connected=true;
        }else if(is_parallal(h1, h2, t1, t2)=='X' and h1.x==h2.x and h1.x==t1.x and h1.x==t2.x){
            if(h1.y>=h2.y and t1.y<=h2.y)
                connected=true;
            else if(h1.y>=t2.y and t1.y<=t2.y)
                connected=true;
            else if(h1.y<=h2.y and t1.y>=h2.y)
                connected=true;
            else if(h1.y<=t2.y and t1.y>=t2.y)
                connected=true;
            else if(h1.y<=h2.y and t1.y>=t2.y)
                connected=true;
            else if(h1.y>=h2.y and t1.y<=t2.y)
                connected=true;
        }else{
            if(h1.x==h2.x and h1.y==h2.y)
                connected=true;
            else if(t1.x==t2.x and t1.y==t2.y)
                connected=true;
            else if(h2.x==t1.x and h2.y==t1.y)
                connected=true;
            else if(h1.x==t2.x and h1.y==t2.y)
                connected=true;
        }
        if(connected)
            pf("yes\n");
        else
            pf("no\n");

    }

    return 0;
}
