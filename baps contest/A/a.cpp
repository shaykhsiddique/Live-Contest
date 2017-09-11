#include<bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define sf2(x, y) scanf("%d %d", &x, &y);
#define pf(n) printf("%d", n)
#define pfn printf("%d\n", n)
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
using namespace std;

int main(){
fli();
int test, n, k;
sf(test);
for(int i=1; i<=test; i++){
    sf2(k, n);
    int poor, nev, own;
    if(k==0){
        poor=n/3;
        own=(n-poor)/3;
        nev=(n-poor)-own;
}else{
    nev=n*2;
    n*=3;
    poor=n/2;
    own=poor*3;
}
printf("Case %d:\n%d\n%d\n%d\n",i , poor, nev, own);
}
return 0;
}
