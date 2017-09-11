#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int test;
    cin>>test;
    string number[1005];
    for(int i=1; i<=test; i++){
        int n;
        cin>>n;
        for(int j=0; j<=n; j++){
            cin>>number[j];
        }
        printf("Case %d:\n",i);
        int digit=number[n].length();

        for(int k=0; k<n; k++){
            int sum=0;
            for(int m=0; m<digit; m++){
                if(number[n][m]==number[k][m])
                {
                    sum++;
                }
            }
            if((sum+1)==digit || sum==digit)
                cout<<number[k]<<endl;
        }
    }

return 0;
}
