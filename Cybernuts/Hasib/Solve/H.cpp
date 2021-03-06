#include<bits/stdc++.h>

//#include<unordered_map>

#define pb push_back
#define nl puts("")
#define sp print(" ")
#define phl printf("hello\n")
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63- __builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define ROF(i,x,y) for(int i= (y); i>=(x); --)
#define CLR(x, y) memset(x, y, sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(), (V).end()), (V).end())
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NUMDIGIT(x, y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x) < 0 ? -(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(), (x).end()
#define LCM(x, y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
#define NORM(x) if(x>=mod) x -=mod;

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair<int, int> pii;
typedef pair<vlong, vlong> pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = (2*acos(0.0));
const double eps = 1e-9;

#ifdef forthright48
    #include<ctime>
//    cloct_t tStart = clock();
    #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)
#endif

struct debugger{
    template<typename T> debugger& operator, (const T &v)
    {
        cerr<<v<<" ";
        return *this;
    }
}dbg;


#define loop(i, n) for(int i=0; i<(n); i++)
#define sf scanf
#define pf printf
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) (v).begin(), (v).end()
#define PI acos(-1.0)
//#define mem(ara, val) mem(ara, val, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define vdump(x) cerr<<#x<<" = "<<x<<endl;
#define dump(args...) cerr,args; cerr<<endl;

template<typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
    out<<"[";
    loop(i, SZ(v))
    {
        if(i) out<<", ";
        out<<v[i];
    }
    out<<"]";
    return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream&out, pair<T1, T2> p)
{
    out<<"("<<p.fr<<", "<<p.sc<<")";
    return out;
}

template<typename T>
ostream& operator,(ostream &out, T x)
{
    out<<x<<" ";
    return out;
}




inline vlong gcd(vlong a, vlong b)
{
    a = ABS(a); b = ABS(b);
    while(b){a = a%b; swap(a,b);}
    return a;
}

vlong ext_gcd(vlong A, vlong B, vlong *X, vlong *Y)
{
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for(r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y)
    {
        q = r2/r1;
        r = r2 % r1;
        x = x2 - (q*x1);
        y = y2 - (q * y1);
    }

    *X = x2;
    *Y = y2;
    return r2;
}

inline vlong modInv(vlong a, vlong m)
{
    vlong x, y;
    ext_gcd(a, m, &x, &y);
    if(x < 0) x += m; /// MOD inv is never negetive
    return x;
}

inline vlong power(vlong a, vlong p)
{
    vlong res = 1, x = a;
    while(p)
    {
        if(p & 1) res = (res * x);
        x = (x*x); p>>=1;
    }

    return res;
}


inline vlong bigmod(vlong a, vlong p, vlong m)
{
    vlong res = 1%m, x = a%m;

    while(p)
    {
        if(p&1) res = (res*x) % m;
        x = (x*x)%m; p >>= 1;
    }
    return res;
}



vlong MATMOD = 1000000007;

//#define x 4

struct MAT{
    vlong a[4][4];
    int row, col;
    MAT() {}
    MAT(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }

    void assign(int r, int c)
    {
        row = r;
        col = c;
    }
    void identity()
    {
        mem();
        loop(i, row) a[i][i] = 1;
    }

    void mem()
    {
        CLR(a, 0);
    }

    MAT operator * (MAT b)
    {
        MAT res(row, b.col);


        loop(i, row)
        {
            loop(j, b.col)
            {
                loop(k, col)
                {
                    //debug(i, j, k);
                    res.a[i][j] = (res.a[i][j] + a[i][k]*b.a[k][j]) % MATMOD;
                    //debug(i, j, k);
                }
            }
        }

        return res;
    }

    MAT operator ^ (vlong p)
    {
        //vdump(row);
        //vdump(col);
        MAT res(row, col); res.identity();
        MAT x = *this;
        while(p)
        {

            if(p & 1)
            {
                res = res * x;

            }

            x = x * x;
            p>>= 1;
        }

        return res;
    }
};




MAT ini(3, 3);
MAT lan(3, 1);


void init()
{
    MAT tmp = ini ^ 2;

    tmp = tmp * lan;

    vdump(tmp.a[2][0]);
}



int main()
{
    #ifdef hasibpc
        // read("input.txt");
        // write("output.txt");
    #endif // hasibpc


    ini.row = 3; ini.col = 3;
    lan.row = 3; lan.col = 1;



    ini.mem();

    ini.a[0][0] = ini.a[0][1] = ini.a[1][0] = ini.a[2][0] = ini.a[2][2] = 1;

    loop(i, 2) lan.a[i][0] = 1;
    lan.a[2][0] = 1;

    //init();


    int kases, kaseno = 0;

    sf("%d", &kases);

    ll N;


    while(kases--)
    {
        sf("%lld", &N);

        pf("Case %d: ", ++kaseno);

        ll ret = 0;

        if(N == 1)
        {
            ret = 8;
        }
        else if(N == 2)
        {
            ret = 16;
        }
        else if(N == 3)
        {
            ret = 40;
        }
        else
        {
            N--;
            MAT tmp = ini ^ N;
            tmp = tmp * lan;
            ret = tmp.a[2][0];

            //vdump(ret);

            N++;

            ret = 16*ret - 8*N;


            ret %= MATMOD;

            if(ret < 0) ret += MATMOD;



        }

        pf("%lld\n", ret);

    }





    return 0;
}


