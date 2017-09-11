#include <bits/stdc++.h>
using namespace std;
#define N       2004

int arr[N], arr1[N];
char ch[N], ch1[N];

int main()
{
    int t, i, j ,caseNo = 1, z=0,u, v, cnt, n, r, sum, n1;
    char pd;
    cin >> t;
    while(t--)
    {
        int bulb = 0;
        cin >> n >> r;
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        for(i = 1; i <= n; i++)
            cin >> ch[i];
        sum = 0;
        pd = ch[1];
        j = 1;
        for(i = 1; i <= n; i++)
        {
            if(pd == ch[i])
                sum+=arr[i];
            else
            {
                arr1[j]= sum;
                ch1[j]= pd;
                pd = ch[i];
                sum = arr[i];
                j++;
            }
        }
        arr1[j]=sum;
        ch1[j] = pd;
        n1 = j;
        /*for(i = 1; i <= n1; i++)
        {
            printf("%d ", arr1[i]);
        }
        puts("");
        for(i = 1; i <= n1; i++)
        {
            printf("%c ", ch1[i]);
        }
        puts("");
        getchar();*/
        sum = 0;
        for(i = 1; i <= n1; i++)
        {
            sum += arr1[i];
            if(sum <= 0)
            {
                sum = 0;
                continue;
            }
            if(sum%(r+r)==0)
            {
                bulb+=sum/(r+r);
                sum = 0;
            }
            else if(sum%(r+r)>r)
            {
                bulb+=sum/(r+r)+1;
                sum = 0;
            }
            else
            {
                bulb+=sum/(r+r)+1;
                sum = -r;
            }
        }
        printf("Case %d: %d\n", caseNo++, bulb);
    }
    return 0;
}




