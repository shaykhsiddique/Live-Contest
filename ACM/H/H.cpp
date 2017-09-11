/*
    LIB 602
    Team 90
    NSU Aristocrats
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl printf("\n")
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


vlong MATMOD = 1e9+7;
struct MAT {
    vlong a[3][3];
    int row, col;

    MAT(){}
    MAT(int r,int c) {
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c ) {
        row = r;
        col = c;
    }
    void identity() {
        mem();
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem() {
        CLR(a,0);
    }
    MAT operator * ( MAT b ) {
        MAT res ( row, b.col );

        for ( int i = 0; i < row; i++ ) {
            for ( int j = 0; j < b.col; j++ ) {
                for ( int k = 0; k < col; k++ ) {
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD;
                }
            }
        }

        return res;
    }

    MAT operator ^ ( vlong p ) {
        MAT res ( row, col); res.identity();
        MAT x = *this;
        while ( p ) {
            if ( p & 1 ) res = res * x;
            x = x * x;
            p >>= 1;
        }
        return res;
    }

    void print() {
        for ( int i = 0; i < row; i++ ) {
            for ( int j = 0; j < col; j++ ) {
                printf ( "%lld ", a[i][j] );
            }
            nl;
        }
    }
};

int main(){
    #ifdef forthright48
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // forthright48

    int kase;

    scanf ( "%d", &kase );

    int cnt = 0;

    while ( kase-- ) {
        long long n;
        scanf ( "%lld", &n );

        MAT coef(3,3);
        coef.a[0][1] = 1;
        coef.a[1][0] = coef.a[1][1] = 1;
        coef.a[2][1] = coef.a[2][2] = 1;

        MAT init(3,1);
        init.a[0][0] = 1;
        init.a[1][0] = 1;
        init.a[2][0] = 1;

        coef = coef ^ (n-1);

        init = coef * init;

        vlong sum = init.a[2][0];

        sum *= 16;
        sum %= MATMOD;

        sum -= 8 * n;
        sum %= MATMOD;
        if ( sum < 0 ) sum += MATMOD;

        printf ( "Case %d: %lld\n", ++cnt, sum );
    }

    return 0;
}
