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



int t, tc = 0;

int n, root;
int a[100005], p[100005], e[100005];
vector<int> v[100005], w[100005];

int ara[100005], ok[100005], res[100005], st[100005], en[100005], cc;

int tree[4*100005];
map<int,int> mm;

void build(int nd, int stt, int enn) {
    if (stt == enn) {
        tree[nd] = 0;
        return;
    }

    int md = (stt+enn)/2;
    build(2*nd,stt,md);
    build(2*nd+1,md+1,enn);

    tree[nd] = 0;

    return;
}

void upd (int nd, int stt, int enn, int pp, int vall ) {
    if (stt == enn) {
        tree[nd] = vall;
        return;
    }

    int md = (stt+enn)/2;

    if (pp <= md) upd(2*nd,stt,md,pp,vall);
    else upd(2*nd+1,md+1,enn,pp,vall);

    tree[nd] = tree[nd*2] + tree[2*nd+1];
    return;
}

int qry(int nd, int stt, int enn, int p1, int p2) {

    debug(nd, stt, enn, p1, p2);

    if (stt > p2 || enn < p1) return 0;
    if (stt >= p1 && enn <= p2) return tree[nd];
    int md = (stt+enn)/2;
    int v1 = qry(2*nd,stt,md,p1,p2);
    int v2 = qry(2*nd+1,md+1,enn,p1,p2);

    debug(nd, stt, enn, p1, p2, v1+v2);
    return v1+v2;
}

void dfs(int pos, int dead, int tot) {

    //debug(pos, dead, tot);

    ok[ pos ] = 1;
    if ( a[pos] < dead ) {
        ok[pos] = 0;
    }

    cc++;
    ara[cc] = a[pos] + tot;
    if ( ok[pos] == 0 ) ara[cc] = 1000000000;
    st[pos] = cc;

    debug("update", ara[cc], cc);

    if (mm.find(ara[cc]) != mm.end()) {
        debug(ara[cc],cc, mm[ ara[cc] ]);
        int ppos = mm[ ara[cc] ];
        upd(1,1,n,ppos,0);
    }

    upd(1,1,n,st[pos],1);
    mm[ ara[cc] ] = st[pos];


    for (int i=0; i<v[pos].size(); i++) {
        int j=v[pos][i];
        int newDead = MAX(0,dead-w[pos][i]);

        //debug("call", pos, " -> ", j, newDead, w[pos][i], w[pos].size(), v[pos].size());
        dfs(j,newDead,tot+w[pos][i]);
    }

    en[pos] = cc;

    debug("query", st[pos], en[pos]);

    res[pos] = qry(1,1,n,st[pos],en[pos]);


    if ( mm.find(1000000000) != mm.end()){
        int baajePos = mm[1000000000];
        if (baajePos >= st[pos] && baajePos <= en[pos]) {
            res[pos]--;
        }
    }

    return;

}

int main(){
    #ifdef forthright48
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // forthright48

    scanf("%d", &t);
    while (tc<t) {
        tc++;
        debug("================== test", tc, "====================");

        scanf("%d", &n);

        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            v[i].clear();
            w[i].clear();
        }

        for (int i=1; i<=n; i++) {
            scanf("%d", &p[i]);
            if (p[i] == 0) {
                root = i;
                continue;
            }
            //v[ i ].pb( p[i] );
            v[ p[i] ].pb( i );
        }

        for (int i=1; i<=n; i++) {
            scanf("%d", &e[i]);
            //debug(i, "---", e[i]);
            if (p[i] == 0) continue;
            //phl;
            //w[ i ].pb( e[i] );
            w[ p[i] ].pb( e[i] );
        }

        build(1,1,n);
        mm.clear();

        cc = 0;
        dfs(root, 0, 0);

        //for (int i=1; i<=n; i++) {
        //    debug(i, "i:",ara[st[i]], st[i], en[i]);
        //}

        printf("Case %d:\n", tc);
        for (int i=1; i<=n; i++) {
            printf("%d\n", res[i]);
        }


    }


    return 0;
}
