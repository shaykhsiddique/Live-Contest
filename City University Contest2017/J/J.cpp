#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    int i,j,t,n,f,l;
    // freopen("in.txt","r",stdin);
    cin>>t;
    string s,a,b;
    while(t--)
    {
        cin>>s;
        f=l=n=0;
        n=s.size();a=b="";
        for(i=0; i<n; i++)
        {
            if((s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o'&&s[i]!='u' && s[i]!='y')&&(s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O'&&s[i]!='U' && s[i]!='Y'))
            {
                f=i;
                break;
            }
            else
                a+=s[i];
        }

        for(i=n-1; i>f; i--)
        {
            if((s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o'&&s[i]!='u' && s[i]!='y')&&(s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O'&&s[i]!='U' && s[i]!='Y'))
            {
                l=i;
                break;
            }
            else
                b+=s[i];
        }


        cout<<a;

        for(i=f; i<=l; i++)
        {
            if((s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o'&&s[i]!='u' && s[i]!='y')&&(s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O'&&s[i]!='U' && s[i]!='Y'))
                cout<<s[i];
        }
        reverse(b.begin(),b.end());
        if(a.size()!=n)
            cout<<b;
        cout<<"\n";
    }
    return 0;
}
