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

char str_tochar(string num){
    int dec=0;
    rep(i, 0, num.size()){
        dec = dec * 10 + ( num[i] - '0' );
    }
    return dec;
}

bool ch[28];
void build_ABC(ll *num){



    //new start
    repe(i, 6, 9){
        if(num[i]>0){
            repe(j, 0, 9){
                if(i==j and num[j]>1){
                    int id = i*10 + j;
                    ch[id-64]=true;
                }else if(i!=j and num[j]>0){
                    int id = i*10 + j;
                    ch[id-64]=true;
                }
            }
        }
    }
    //new end

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//fli();
//flo();
    int test;
    ll nu[11];
    string num, chk;
    cin>>test;
    repe(cc, 1, test){
        memset(ch, 0, sizeof(ch));
        memset(nu, 0, sizeof(nu));
        cin>>num;
        rep(i, 0, num.size()){
            nu[num[i]-'0']++;
        }
        build_ABC(nu);
        repe(i, 1, 26){
            if(ch[i])
                pf("%c", i+64);
        }bl;
    }
    return 0;
}

