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
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

// Shaykh Siddique

inline bool invalid(char ch){
    if(tolower(ch)=='a' or tolower(ch)=='e' or tolower(ch)=='i' or tolower(ch)=='o' or tolower(ch)=='u' or tolower(ch)=='y')
        return true;
    return false;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//fli();
//flo();
    int test;
    cin>>test;
    string str, pref, suff, fin;
    while(test--){
        cin>>str;
        fin.clear();
        pref.clear();
        suff.clear();
        bool check_pe=false, check_vo=false;
        int ind_pef=0;
        for(int i=0; i<str.size(); i++){
            if(invalid(str[i])){
                pref.pb(str[i]);
                ind_pef=i;
            }else{
                check_pe=true;
                break;
            }
        }
        int ind_suf=str.size();
        for(int i=str.size()-1; i>=0; i--){
            if(invalid(str[i]) and check_pe){
                suff.pb(str[i]);
                ind_suf=i;
            }else{
                break;
            }
        }
        for(int i=ind_pef; i<ind_suf; i++){
            if(!invalid(str[i]))
                fin.pb(str[i]);
        }
        reverse(suff.begin(), suff.end());
        string ans;
        ans=pref+fin+suff;
        cout<<ans<<endl;
    }
    return 0;
}

