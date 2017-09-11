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
#define X first
#define Y second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define mod1 1000000007
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




//segment tree tamplate start


vector<int>tree;


void build (int v, int tl, int tr){

    if (tl == tr){
        tree[v] = 1;
    }
    else{
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
    }
}



int get(int v, int tl, int tr, int pos){
    if (tl == tr)
        return tree[v]%mod1;
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return (tree[v] + (get (v*2, tl, tm, pos)%mod1))%mod1;
    else
        return (tree[v] + get (v*2+1, tm+1, tr, pos)%mod1)%mod1;
}



void update (int v, int tl, int tr, int l, int r, int add){
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[v]%= mod1;
        tree[v] += add;
        tree[v]%= mod1;
        return;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}



//segment tree tamplate end








int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test, n, m, s, l, r;
    sfi(test);
    repe(cc, 1, test){
        tree.clear();
        sfi2(n, m);
        tree.resize(5*m);
        vector<pair<int,PAIR>> cmd;
        repe(i, 1, m){
            sfi2(s, l); sfi(r);
            cmd.pb(make_pair(s, make_pair(l, r)));
        }
        int c[m+2];
        memset(c, 0, sizeof(c));

        build(1,0,m-1);

        for(int i = m-1; i>=0; i--)
        {
            c[i] = get(1,0,m-1,i);
            if(c[i] < 0)c[i]+=mod1;
            if((cmd[i]).X==1)continue;
            else
            {
                update(1,0,m-1,(cmd[i].Y).X-1,(cmd[i].Y).Y-1,c[i]%mod1);
            }
        }

        int b[n+3];
        memset(b, 0, sizeof(b));
        rep(i,0,m){
            if((cmd[i]).X==2)continue;
            else
            {
                b[(cmd[i]).Y.X]+=c[i];
                b[(cmd[i]).Y.X]%=mod1;
                b[(cmd[i]).Y.Y+1]-=c[i];
                b[(cmd[i]).Y.Y+1]%=mod1;
            }
        }
        rep(i,1,n+2){
            b[i]+=b[i-1];
            b[i]%=mod1;
        }
        rep(i,1,n+2){
            if(b[i] < 0 )
                b[i]+=mod1;
        }
        rep(i,1,n+1){
            pf("%d ",b[i]);
        }
        bl;
    }
    return 0;
}



