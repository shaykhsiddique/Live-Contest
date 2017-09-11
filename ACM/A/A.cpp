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
        cerr << v << "";
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


int N, M, X, uu, vv;
vector<int> v[100005];

bool dfs(int pos) {

    //debug(pos, " " ,v[pos].size());

    if (v[pos].size() == 0) return true;

    for (int i=0; i<v[pos].size(); i++) {
        int j = v[pos][i];
        if ( dfs(j) == true ) return false;
    }
    return true;
}

int main(){
    #ifdef forthright48
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // forthright48


    int t, tc = 0;
    scanf("%d", &t);
    while (tc<t) {
        tc++;

        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &X);

        for (int i=0; i<=N; i++) {
            v[i].clear();
        }

        for (int i=0; i<M; i++) {
            scanf("%d %d", &uu, &vv);
            //debug(uu, " " ,vv);
            v[uu].pb(vv);
        }

        if (dfs(X) == true) {
            printf("Case %d: No\n", tc);
        }
        else {
            printf("Case %d: Yes\n", tc);
        }
    }

    return 0;
}
