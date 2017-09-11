#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      in(n)             scanf("%d",&n)
#define      out(n)            printf("%d\n",n)
#define      llin(n)           scanf("%lld",&n)
#define      llout(n)          printf("%lld\n",n)

typedef long long ll;
ll mod1 = 1000000007;
ll mod2 = 1000000009;

vi t;

void build (int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = 1;
	}
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
	}
}

void update (int v, int tl, int tr, int l, int r, int add) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		t[v]%= mod1;
		t[v] += add;
		t[v]%= mod1;
		return;
	}
	else {
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), add);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
	}
}

int get (int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v]%mod1;
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return (t[v] + (get (v*2, tl, tm, pos)%mod1))%mod1;
	else
		return (t[v] + get (v*2+1, tm+1, tr, pos)%mod1)%mod1;
}


int main() {
    int x;in(x);
    while(x--) {

        int n,m,s,l,r;
        in(n);in(m);
        t.clear();t.resize(4*m+4);
        vector<pair<int,pii>> cmd;
        For(i,0,m) {
            scanf("%d %d %d",&s,&l,&r);
            cmd.pb(mp(s,mp(l,r)));
        }

        int c[m+2]; fill(c);

        build(1,0,m-1);

        for(int i = m-1;i>=0;i--) {
            c[i] = get(1,0,m-1,i);
            if(c[i] < 0)c[i]+=mod1;
            if((cmd[i]).X==1)continue;
            else {
                update(1,0,m-1,(cmd[i].Y).X-1,(cmd[i].Y).Y-1,c[i]%mod1);
            }
        }

        int b[n+3];fill(b);
        For(i,0,m) {
            if((cmd[i]).X==2)continue;
            else {
                b[(cmd[i]).Y.X]+=c[i];
                b[(cmd[i]).Y.X]%=mod1;
                b[(cmd[i]).Y.Y+1]-=c[i];
                b[(cmd[i]).Y.Y+1]%=mod1;
            }
        }
        For(i,1,n+2){b[i]+=b[i-1];b[i]%=mod1;}
        For(i,1,n+2) if(b[i] < 0 )b[i]+=mod1;
        For(i,1,n+1) printf("%d ",b[i]);
        cout<<endl;
    }

    return 0;
}
