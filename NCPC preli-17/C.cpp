#include <bits/stdc++.h>
using namespace std;
#define N       2004

int arr[N];
char ch[N];

int main()
{
    int t, i, j ,caseNo = 1, z=0,u, v, cnt, n, r, sum;
    char pd;
    cin >> t;
    //scanf("%d", &t);
    //getchar();
    while(t--)
    {
        int bulb = 0;
        cin >> n >> r;
        //scanf("%d %d", &n, &r);
        //getchar();
        for(i = 1; i <= n; i++)
            cin >> arr[i];
            //scanf("%d", &arr[i]);
        //getchar();
        for(i = 1; i <= n; i++)
            cin >> ch[i];
            //scanf("%c", &ch[i]);
        //getchar();
        sum = 0;
        pd = ch[1];
        for(i = 1; i <= n; i++)
        {
            if(pd == ch[i])
            {
                sum += arr[i];
                pd = ch[i];
            }
            else
            {
                sum+=arr[i];
                if(sum%(r+r)==0)
                {
                     bulb+=sum/(r+r);
                     sum = 0;
                     pd = ch[i];
                     printf("1 ");
                }
                else if(sum%(r+r)>r)
                {
                    bulb+=sum/(r+r)+1;
                    sum = 0;
                    pd = ch[i];
                    printf("2 ");
                }
                else
                {
                    bulb+=sum/(r+r)+1;
                    sum = -r;
                    pd = ch[i];
                    printf("3 ");
                }
            }
            cout << bulb << endl;
        }
        //cout << sum << endl;
        if(sum %(r+r)==0)
            bulb+=sum/(r+r);
        else
            bulb+=sum/(r+r)+1;
        printf("Case %d: %d\n", caseNo++, bulb);

    }
    return 0;
}



