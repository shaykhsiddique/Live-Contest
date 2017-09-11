#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define F first
#define S second
#define M 80

string str="0123456789ABCDEF";

string func(string str1)
{
    ll num=0;
    for(int i=0; i<str1.size(); i++)
    {
        if('0'<=str1[i] && str1[i]<='9')
        {
            num=(num*10)+(str1[i]-'0');
        }
    }

    if(num==0)
        return "0";

    string s;
    while(num)
    {
        s+=str[(num%16)];
        num/=16;
    }

    reverse(s.begin(), s.end());
    return s;
}

ll func1(string str1)
{
    ll num=0, mul=1;
    for(int i=str1.size()-1; i>=0; i--)
    {
        if('0'<=str1[i] && str1[i]<='9')
        {
            num=num+(mul*(str1[i]-'0'));
        }
        else
        {
            num=num+(mul*(str1[i]-'A'+10));
        }
        mul*=16;
    }
    return num;
}

int main()
{
    string str1, temp, res;
    while(cin >> str1)
    {
        if(str1[0]=='-')
        {
            break;
        }

        if(str1.size()>2)
        {
            temp="";
            if(str1[0]=='0' && str1[1]=='x')
            {
                for(int i=2; i<str1.size(); i++)
                {
                    temp+=str1[i];
                }
                pf("%lld\n", func1(temp));
            }
            else
            {
                pf("0x%s\n", func(str1).c_str());
            }
        }
        else
        {
            pf("0x%s\n", func(str1).c_str());
        }
    }

    return 0;
}