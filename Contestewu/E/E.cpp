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
#define MAX 100010
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
using namespace std;

int arr[MAX],tree[MAX*3],lazy[MAX*3];

void build_tree(int node,int a,int b){
    if(a>b) return;
    if(a==b) {
        tree[node]=arr[a];
        return;
    }
    build_tree(node*2,a,(a+b)/2);
    build_tree(node*2+1,1+(a+b)/2,b);
    tree[node]=max(tree[node*2],tree[node*2+1]);
    if(tree[node]>2) tree[node]=2;
}

void update_tree(int node,int a,int b,int i,int j,int value){
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(tree[node]>2) tree[node]=2;
        if(a!=b){
            lazy[node*2]+=lazy[node];
            if(lazy[node*2]>2) lazy[node*2]=2;
            lazy[node*2+1]+=lazy[node];
            if(lazy[node*2+1]>2) lazy[node*2+1]=2;
        }
        lazy[node]=0;
    }
    if(a>b or a>j or b<i){
        return;
    }
    if(a>=i and b<=j){
        tree[node]+=value;
        if(tree[node]>2) tree[node]=2;
        if(a!=b){
            lazy[node*2]+=value;
            if(lazy[node*2]>2) lazy[node*2]=2;
            lazy[node*2+1]+=value;
            if(lazy[node*2+1]>2) lazy[node*2+1]=2;
        }
        return;
    }
    update_tree(node*2,a,(a+b)/2,i,j,value);
    update_tree(node*2+1,1+(a+b)/2,b,i,j,value);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query_tree(int node,int a,int b,int i,int j){
    if(a>b or a>j or b<i) return INT_MIN;
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(tree[node]>2) tree[node]=2;
        if(a!=b){
            lazy[node*2]+=lazy[node];
            if(lazy[node*2]>2) lazy[node*2]=2;
            lazy[node*2+1]+=lazy[node];
            if(lazy[node*2+1]>2) lazy[node*2+1]=2;
        }
        lazy[node]=0;
    }
    if(a>=i and b<=j) return tree[node];
    int q1=query_tree(node*2,a,(a+b)/2,i,j);
    int q2=query_tree(node*2+1,1+(a+b)/2,b,i,j);
    int res=max(q1,q2);
    return res;
}

int main(){
    fli();
//    int N=100000;
//    update_tree(1,0,N-1,0,6,5);
//    update_tree(1,0,N-1,7,10,12);
//    update_tree(1,0,N-1,10,N-1,100);
//    cout<<query_tree(1,0,N-1,0,N-1)<<endl;
    int n,m,a,b;
    while(sc2(n,m)==2){
        build_tree(1,0,MAX-1);
        mems(lazy,0);
        while(m--){
            sc2(a,b);
            a--;
            b--;
            update_tree(1,0,n-1,a,b,1);
        }
        int ans=0;
        prn(query_tree(1,0,n-1,0,n-1)-n);
    }
    return 0;
}




