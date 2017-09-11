#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:                |
    |------------------------------------------------------------------|
*/

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d:\n", i)
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
#define fi first
#define se second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
#define ll_MAX 9223372035
using namespace std;

              // Code starts from here
int alph[28];
int frequency(string word, int k){
    memset(alph, 0, sizeof(alph));

    rep(i, 0, word.size()){
        alph[word[i]-'a']++;
    }
    sort(alph, alph+26);
    int ans=INT_MAX;

    rep(i, 0, 26){
        int sum=0;
        rep(j, 0, i){
            sum+=alph[j];
        }
        for(int j=25; j>i; j--){
            if(alph[j]>alph[i]+k){
                sum+=alph[j]-alph[i]-k;
            }
        }
        ans=min(ans, sum);
    }
    return ans;

}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli();
//flo();
    int test, k;
    string word;
    cin>>test;
    repe(cc, 1, test){
        cin>>word>>k;
        cout<<frequency(word, k)<<endl;
    }

    return 0;
}

