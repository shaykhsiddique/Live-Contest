
deadlock 's source code for C
Memory: 11059 KB 		Time: 280 MS
Language: C++14(g++ 4.9.2) 		Result: Accepted
VJ RunId: 7382124

Private Public

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79

#include<bits/stdc++.h>
using namespace std;

int ara[1005][1005],khara[1005][1005],n,m;

int main()
{
  int t,tt,i,j,a,b,c,d,e,f,g,h;
  cin>>tt;
  for(t=1; t<=tt; t++)
  {
    cin>>n>>m;
    c=1000000;
    e=f=g=h=0;
    for(i=0; i<n; i++)
    {
      for(j=0; j<m; j++)
        cin>>ara[i][j],c=min(c,ara[i][j]);
    }
    for(i=0; i<n; i++)
    {
      a=0;
      for(j=0; j<m; j++)
      {
        a+=ara[i][j];
        khara[i][j]=a;
        if(a>0)
          a=0;
      }
    }
    for(i=0; i<n; i++)
    {
      a=0;
      for(j=m-1; j>=0; j--)
      {
        a+=ara[i][j];
        khara[i][j]+=a;
        if(a>0)
          a=0;
      }
    }

    for(i=0; i<m; i++)
    {
      a=0;
      for(j=0; j<n; j++)
      {
        a+=ara[j][i];
        khara[j][i]+=a;
        if(a>0)
          a=0;
      }
    }
    for(i=0; i<m; i++)
    {
      a=0;
      for(j=n-1; j>=0; j--)
      {
        a+=ara[j][i];
        khara[j][i]+=a;
        if(a>0)
          a=0;
      }
    }
    b=0;
    for(i=0; i<n; i++)
    {
      for(j=0; j<m; j++)
      {
        a=khara[i][j]-(3*ara[i][j]);
        b=min(a,b);
      }
    }
    if(b>=0)
      b=max(b,c);
    cout<<b<<endl;
  }
  return 0;
}
