using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define ss(x)           scanf("%s", x)
#define pf              printf
#define pb              push_back
#define N               100005
#define PI              3.40954185
#define F               first
#define S               second

typedef long long int ll;

string tree[4*N+5];
char str[N];

void makeTree(int s, int e, int idx)
{
    if(s == e)
    {
        tree[idx] = str[s];
        return;
    }
    int mid = (s+e)/2;
    int left = 2*idx;
    int right = left+1;

    makeTree(s, mid, left);
    makeTree(mid+1, e, right);

    tree[idx] = tree[left] + tree[right];
}

void update(int s, int e, int index, int idx)
{
    if(s > index || e < index)
        return;
    if(s == index && e == index)
    {
        if(tree[idx] == "1")
            tree[idx] = "0";
        else
            tree[idx] = "1";
        return;
    }
    int mid = (s+e)/2;
    int left = 2*idx;
    int right = left+1;

    update(s, mid, index, left);
    update(mid+1, e, index, right);

    tree[idx] = tree[left]+tree[right];
}

string query(int s, int e, int l, int r, int idx)
{
    if(s > r || e < l)
        return "-1";
    if(s >= l && e <= r)
        return tree[idx];

    int mid = (s+e)/2;
    int left = 2*idx;
    int right = left+1;

    string str1 = query(s, mid, l, r, left);
    string str2 = query(mid+1, e, l, r, right);

    if(str1 == "-1")
        return str2;
    if(str2 == "-1")
        return str1;
    else
        return str1+str2;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, q, i, j, x, y, z, caseNo = 1, mode;

    si(t);
    getchar();

    while(t--)
    {
        fill(tree, tree+4*N+3, "0");

        si(n);
        si(q);
        getchar();
        ss(str);
        getchar();

        makeTree(0, n-1, 1);
        pf("Case %d:\n", caseNo++);
        for(i = 1; i <= q; i++)
        {
            si(mode);
            if(mode == 0)
            {
                si(x);
                getchar();
                update(0, n-1, x, 1);
                //cout << tree[1] << endl;
                //for(i = 1; i <= 45; i++)
                    //cout << tree[i] << endl;
            }
            else
            {
                string str1, str2;
                str1 = "";
                str2 = "";
                si(x);
                si(y);
                si(z);
                getchar();
                str1 = query(0, n-1, x, x+z-1, 1);
                //cout <<"String 1 : "<<  str1 << endl;

                str2 = query(0, n-1, y, y+z-1, 1);
                //cout <<"String 2 : "<<  str2 << endl;

                if(str1 == str2)
                    pf("1\n");
                else
                    pf("0\n");
            }
        }
    }

    return 0;
}

