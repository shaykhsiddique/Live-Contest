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

/****************************************************************/

vector<vlong> xlimit;
#define SIZE 100010
pair<vlong,vlong> orig[SIZE];

vector<vlong> arr[SIZE];

struct node {
    vector<vlong> vrr;
}tnode[4*SIZE];

void build ( int t, int b, int e ) {
    int m = ( b + e ) / 2;
    int u = t * 2;
    int v = u + 1;

    if ( b == e ) {
        tnode[t].vrr = arr[b];
        return;
    }

    build(u,b,m);
    build(v,m+1,e);

    tnode[t].vrr.resize(tnode[u].vrr.size()+tnode[v].vrr.size());
    merge(tnode[u].vrr.begin(),tnode[u].vrr.end(),tnode[v].vrr.begin(),tnode[v].vrr.end(),tnode[t].vrr.begin());
}

vlong ql, qr, qy, qres;
void query ( int t, int b, int e ) {
    int m = ( b + e ) / 2;
    int u = t * 2;
    int v = u + 1;

    if ( ql <= b && e <= qr ) {
        qres += upper_bound(ALL(tnode[t].vrr),qy) - tnode[t].vrr.begin();
        return;
    }
    if ( e < ql || qr < b ) return;

    query(u,b,m);
    query(v,m+1,e);
}
int NNN;

int findYPoint ( int l, int r, vlong y ) {

    qres = 0;
    ql = l;
    qr = r;
    qy = y;

    query(1,0,NNN-1);

    return qres;
}

int main(){
    #ifdef forthright48
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // forthright48

    int kase;
    scanf ( "%d", &kase );

    int cnt = 0;

    while ( kase-- ) {
        int p, q;
        scanf ( "%d %d", &p, &q );

        xlimit.clear();

        FOR(i,0,p-1) {
            int x,y;

            scanf ( "%d %d", &x, &y );

            vlong a = x - y;
            vlong b = x + y;

            orig[i] = MP(a,b);

            xlimit.pb(a);
        }

        sort(ALL(xlimit)); UNIQUE(xlimit);

        FOR(i,0,SIZE-1) {
            arr[i].clear();
        }

        FOR(i,0,p-1) {
            vlong x = orig[i].ff;
            x = lower_bound(xlimit.begin(),xlimit.end(),x) - xlimit.begin();
            arr[x].pb(orig[i].ss);
        }

        FOR(i,0,SIZE-1) {
            sort(ALL(arr[i]));
        }

        NNN = xlimit.size();

        build(1,0,NNN-1);

        printf ( "Case %d:\n", ++cnt );

        FOR(i,0,q-1) {
            int x, y;
            scanf ( "%d %d", &x, &y );

            vlong a = x - y;
            vlong b = x + y;

            vlong low = 0, high = 2000000000;
            while ( low <= high ) {
                vlong mid = ( low + high ) / 2;

                if ( mid == 0 ) {
                    low = mid + 1;
                    continue;
                }

                vlong lpos = lower_bound(xlimit.begin(),xlimit.end(),a-mid+1) - xlimit.begin();
                vlong rpos = upper_bound(xlimit.begin(),xlimit.end(),a+mid-1) - xlimit.begin() - 1;


                if ( lpos > rpos ) {
                    low = mid + 1;
                }
                else {

                    vlong ylow = b - mid;
                    vlong yhigh = b + mid;

                    vlong q1 = findYPoint(lpos,rpos,ylow);
                    vlong q2 = findYPoint(lpos,rpos,yhigh-1);

                    if ( q1 == q2) {
                        low = mid + 1;
                    }
                    else high = mid - 1;

                }
            }

            vlong side = 2 * ( low - 1 );

            printf ( "%lld\n", side );

        }
    }

    return 0;
}
