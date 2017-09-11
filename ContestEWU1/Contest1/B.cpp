#include<bits/stdc++.h>

using namespace std;

int main()
{
    int number, ans=0;
    int sum=0;
    cin>>number;
    for(int i=1;i<=number;i++){
        int total=sqrt(i);
        ans++;
        for(int j=2; j<=total; j++){
            if(i%j==0){
                                                //cout<<"*";
                ans++;
            }
        }
        sum+=ans;
        ans=0;
                                            //cout<<ans<<endl;
    }
   cout<<sum<<endl;
    return 0;
}
