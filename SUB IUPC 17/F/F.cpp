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
#define find puts("I am here")
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,x,n) for(int i=x;i<n;i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique

inline bool is_devisable(char* ret,ll p) {
	ll res = 0,len=strlen(ret);
	for (int i = 0; i < len; ++ i) {
		res = res * 10 + ret[i] - '0';
		res %= p;
	}
	return !res;
}

int main(){
    //fli();
    int t;
    sfi(t);
    ll a,b,rem;
    char st[30];
    repe(cc,1,t+1){
        pfc(cc);
        scanf("%lld%lld",&a,&b);
        if((a<0 and b>=0) or (a>=0 and b<0) ) putchar('-');
        if(a%b==0){
            printf("%lld\n",a/b);
            continue;
        }
        printf("%lld.",a/b);
        rem=a%b;
        int i=0;
        while(rem){
            st[i]=rem%10+'0';
//            cout<<" adding "<<rem%10<<endl;
            rem/=10;
            i++;
        }
        st[i]=0;
        reverse(st,st+i);
    }
    return 0;
}

