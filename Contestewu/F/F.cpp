#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define scs(x) scanf("%s",x)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
#define memc(x,y) memcpy(&x,&y,sizeof(x))
#define mems(x,y) memset(x,y,sizeof(x))
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define rep(i,v) for(int i=0;i<v;i++)
#define repe(i,v) for(int i=0;i<=v;i++)
#define Rep(i,x,v) for(int i=x;i<v;i++)
#define Repe(i,x,v) for(int i=x;i<=v;i++)
#define repv(i,x) for(auto i=x.begin();i!=x.end();i++)
#define reprv(i,x) for(auto i=x.rbegin();i!=x.rend();i++)
#define dbg(x) cout << #x << " : " << x << endl
#define pb push_back
#define bl putchar('\n')
#define gcc getchar()
#define pcc putchar
#define si size
#define fi first
#define se second
#define MAX 1
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
using namespace std;

int main(){
//    fli();
    char st[1000000];
    int a,b;
    int aa,bb;
    double ans;
    while(scanf("%s",st)==1){
        sc2(a,b);
        if(b==0 or a==0){
            printf("%s 0\%\n",st);
            continue;
        }else if(a*10>b){
            printf("%s 100\%\n",st);
            continue;
        }
        ans=(a*10)/(double)b;
        aa=ans*100;
        bb=ans*1000;
        if(bb%10>4)aa++;
        printf("%s %d\%\n",st,aa);
    }
    return 0;
}
