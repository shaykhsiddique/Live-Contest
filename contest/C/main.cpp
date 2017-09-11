#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn(n) printf("%d\n", n)
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
#define mem(n, k) memset(n, k, sizeof(n))
#define MOD 100000007
using namespace std;

int main(){
//fli();
    int test;
    sf(test);
    loope(1, test){
    bool check=true;
    int x1, y1, x2, y2, c1, c2, r;
    sf2(x1, y1);
    sf2(x2, y2);
    sf2(c1, c2);
    sf(r);
    double ans=sqrt((x2-x1)+(y2-y1));
    if(max(x1, x2)<=(c1+r) && min(x1, x2)>=c1+r){
        if(max(y1, y2)>=c2+r && min(y1,y2)<=c2+r){
            int j =r+c1;
            double flag=sqrt((j-c2)+(x2-x1));
            j+=1;
            double flag2=sqrt((j-c2)+(y2-11));
//            cout<<flag+flag2<<endl;
            printf("Case %d: %.3lf\n", i, flag+flag2);
            check=false;
        }

    }
    if(true)
    printf("Case %d: %.3lf\n", i, ans);
    }

    return 0;
}
