#include<bits/stdc++.h>

using namespace std;
#define pause system("pause");
#define mod 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size()  )
#define sqr(x) ( (x) * (x) )
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
#define pf printf
#define reset(x,v)  memset (x,v,sizeof(x) ) ;
#define what_is(x) cerr<<#x<<" is "<<x<<"\n";

vector<int>lst[1004];
int visit[1004];
int cnt;
int n,m;

void dfs(int nod)
{
    if(visit[nod]) return;

    visit[nod]=1;
    cnt++;

    for(int i=0;i<sz(lst[nod] );i++ )
    {
        dfs(lst[nod][i] );
    }
}

bool bfs()
{


    reset(visit,0);

    queue<int>q;
    q.push(0);

    visit[0]=1;

    while(!q.empty())
    {
        int nw=q.front();
        q.pop();

        for(int i=0;i<sz(lst[nw] );i++ )
        {
            if(!visit[lst[nw][i] ] )
            {
                visit[lst[nw][i] ] = 1 + visit[nw];
                q.push(nw);
            }
            else if(( visit[lst[nw][i] ]== visit[nw] )   )
            {
                return false;
            }
        }

    }

    return true;
}


#define in(x) scanf("%d",&x)


int main()
{
    #ifdef kimbbakar
    freopen("in.txt","r",stdin );

    #endif // kimbbakar

    int t,tcase=1;

    in(t);

    while(t--)
    {
        in(n),in(m);

        for(int i=0;i<=n;i++)
            lst[i].clear();

        int x,y;

        bool ok=false;

        for(int i=0;i<m;i++ )
        {
            in(x),in(y);

            if(x!=y) ok=true;

            lst[x].pb(y);
            lst[y].pb(x);
        }

        pf("Case %d: ",tcase++);

        if(n<=1)
            pf("No\n");
        else if(n==2)
        {
            if(ok)
                pf("No\n");
            else pf("Yes\n");
        }

        else
        {
            reset(visit,0);
            cnt=0;
            dfs(0);
            if(cnt==n)
            {
                if(bfs())
                {
                    if(m<=3*n-6 )
                        pf("No\n");
                    else pf("Yes\n");
                }
                else
                {
                    if(m<=2*n-4 )
                        pf("No\n");
                    else pf("Yes\n");
                }
            }
            else pf("Yes\n") ;
        }

    }


    return 0;
}
