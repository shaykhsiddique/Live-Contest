#include<bits/stdc++.h>

#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
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
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique

set<pair<string,ll>>s1;
set<pair<ll,string>>s2;
map<string,ll>m;
char st[110];

int main(){
//    fli();
    ll n,c,x,t,save,tm,val;
    scanf("%lld",&t);
    for(int cc=1;cc<=t;cc++){
        pfc(cc);
        s1.clear();
        s2.clear();
        m.clear();
        tm=0;
        save=0;
        scanf("%lld%lld%lld",&n,&x,&c);
//        cout<<n<<" "<<x<<" "<<c<<endl;
        while(n--){
            scanf("%s",st);
            tm++;
            if(m[st]!=0){
                val=m[st];
                s1.erase({st,val});
                s2.erase({val,st});
                s1.insert({st,tm});
                s2.insert({tm,st});
                m[st]=tm;
                save+=x;
            }else if(s1.size()==c){
                s1.erase({s2.begin()->second,s2.begin()->first});
                m[s2.begin()->second]=0;
                s2.erase(s2.begin());
                s1.insert({st,tm});
                s2.insert({tm,st});
                m[st]=tm;
            }else if(s1.size()<c){
                s1.insert({st,tm});
                s2.insert({tm,st});
                m[st]=tm;
            }
        }
        printf("%lld\n",save);
    }
    return 0;
}
