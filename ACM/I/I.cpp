/*
    LIB 602
    Team 90
    NSU Aristocrats
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl prinf("\n")
#define sp printf(" ")
#define phl printf("Hello\n")
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;if(x<0)x+=mod;
#define dbgA(A,i) debug("[",i,"] = ", A[i])
#define SET(N,x) ((N)|(1<<(x)))
#define CHECK(N,x) (((N)&(1<<(x)))!=0)

typedef long long vlong;
typedef long long LL;
typedef unsigned long long uvlong;

#ifdef forthright48
    #include <ctime>
    clock_t tstart = clock();
    #define debug(args...) {dbg,args; cerr<<endl;}
    #define bug debug("Bug @ line :",__LINE__)
#else
    #define debug(args...)
    #define bug
#endif // forthright48

struct debugger {
    template<typename T> debugger& operator , (const T& v ) {
        cerr << v << " ";
        return *this;
    }
}dbg;

inline vlong gcd(vlong a,vlong b){
    a = ABS(a);
    b = ABS(b);
    while(b){
        a = a%b;
        swap(a,b);
    }
    return a;
}

LL ext_gcd(LL A,LL B,LL *X,LL *Y){
    LL x2,y2,x1,y1,x,y,r2,r1,q,r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for(r2 = A, r1 = B; r1 != 0; r2 = r1,r1 = r,x2 = x1,y2 = y1,x1 = x,y1 = y){
        q = r2/r1;
        r = r2%r1;
        x = x2 - (q*x1);
        y = y2 - (q*y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline LL modInv(LL a, LL m){
    LL x,y;
    ext_gcd(a,m,&x,&y);
    x %= m;
    if(x<0) x += m;
    return x;
}

inline LL power(LL a, LL p){
    LL res = 1,x = a;
    while(p){
        if(p & 1) res = (res*x);
        x = (x*x); p >>= 1;
    }
    return res;;
}

inline LL bigmod(LL a, LL p, LL m){
    LL res = 1%m,x = a%m;
    while(p){
        if(p&1) res = (res*x)%m;
        x = (x*x)%m; p>>= 1;
    }
    return res;
}

const vlong inf = 2147383647;
const double pi = 2*acos(0.0);
const double eps = 1e-8;

vlong t, tc = 0;

const vlong mod = 1e9+7;
#define SIZE 1000000
int people[SIZE], ntype[SIZE];

vector < pair< int ,int > > seg;

vlong fact[SIZE];

vlong nck ( vlong n, vlong k ) {
    vlong res = fact[n] * modInv(fact[k],mod);
    res %= mod;
    res *= modInv(fact[n-k],mod);
    res %= mod;

    return res;
}

int main(){
    fact[0] = 1;
    FOR(i,1,SIZE-10) {
        fact[i] = (fact[i-1] * i ) % mod;
    }

    #ifdef forthright48
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // forthright48

    int kase;
    scanf ( "%d", &kase );

    int cnt = 0;
    while (kase--) {

        int n, m;
        scanf("%d %d", &n, &m);

        FOR(i,1,m) {
            scanf ( "%d", &people[i] );
        }
        people[0] = 0;
        people[m+1] = n + 1;

        FOR(i,1,m) {
            scanf ( "%d", &ntype[i] );
        }
        ntype[0] = 0;
        ntype[m+1] = 0;

        m += 2;

        seg.clear();

        vlong total = 0;
        FOR(i,0,m-2) {
            if ( ntype[i] == 2 || ntype[i+1] == 2 ) continue; ///Next segment is protected
            else if ( ntype[i] == 0 && ntype[i+1] == 0 ) continue; ///Both good
            else if ( ntype[i] == 1 && ntype[i+1] == 1 ) {
                ///Both bad
                seg.pb ( MP(people[i+1]-people[i]-1,2) );
                total += people[i+1]-people[i]-1;
            }
            else {
                ///One bad
                seg.pb ( MP(people[i+1]-people[i]-1,1) );
                total += people[i+1]-people[i]-1;
            }
        }

        vlong res = 1;

        FOR(i,0,SZ(seg)-1) {
            int len = seg[i].ff;
            res *= nck(total,len); res %= mod;
            total -= len;

            if ( seg[i].ss == 2 ) {
                res *= bigmod(2,len,mod);
                res %= mod;
            }
        }

        printf ( "%lld\n", res );
    }


    return 0;
}
