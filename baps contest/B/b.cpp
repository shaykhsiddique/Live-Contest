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

map<string, int> str;

int main(){
fli();
int test;
sf(test);
for(int i=1; i<=test; i++){
    str.clear();
    int n;
    sf(n);
    string ans;
    int maxm=0;
    for(int j=0;j <n; j++){
        string line;
        cin>>line;
        str[line]++;
        if(str[line]>maxm){
            ans=line;
            maxm=str[line];
        }
    }
    printf("Case %d: ", i);
    cout<<ans<<endl;
}
return 0;
}
