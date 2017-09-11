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

#define sf scanf
#define pf printf
#define sfi(n) scanf("%d", &n)
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

ll ind_x[1010];
ll ind_y[1010];
ll color[1010];

bool check_valid(int q, int col){
 bool can_color = true;
        bool rc_ev=false;
        bool rc_od=false;
        bool r_ev_c_od = false;
        bool r_od_c_ev = false;
        rep(i, 0, q){
            if(color[i]==col){
                    if(ind_x[i]%2==0 and ind_y[i]%2==0){
                        if(rc_od or r_od_c_ev or r_ev_c_od){
                            can_color=false;
                            break;
                        }else
                            rc_ev=true;
                    }else if(ind_x[i]%2==1 and ind_y[i]%2==1){
                        if(rc_ev or r_ev_c_od or r_od_c_ev){
                            can_color=false;
                            break;
                        }else{
                            rc_od=true;
                        }
                    }else if(ind_x[i]%2==0 and ind_y[i]%2==1){
                        if(rc_od or rc_ev or r_od_c_ev){
                            can_color=false;
                            break;
                        }else{
                            r_ev_c_od=true;
                        }
                    }else if(ind_x[i]%2==1 and ind_y[i]%2==0){
                        if(rc_od or rc_ev or r_ev_c_od){
                            can_color=false;
                            break;
                        }else{
                            r_od_c_ev=true;
                        }
                    }
            }
        }
        return can_color;
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int test;
    ll n, q;
    sfi(test);
    repe(cc, 1, test){
        memset(color, 0, sizeof(color));
        sfl2(n, q);
        rep(i, 0, q){
            sfl2(ind_x[i], ind_y[i]);sfl(color[i]);
        }
       bool can_color=true;
       can_color=check_valid(q, 1);
       if(can_color)
            can_color=check_valid(q, 2);

        if(can_color)
            pf("yes\n");
        else
            pf("no\n");

    }

    return 0;
}
