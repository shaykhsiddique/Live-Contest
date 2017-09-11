#include<bits/stdc++.h>
using namespace std;
int main(){
long long num, x, k, j;
cin>>num;
while(num!=-1){
    long long b=sqrt(num);
    if(b*b==num){
        x=b;
        k=1;
    }
    else{
        for(j=num; j>0; j--){
            if(fmod(sqrt(num), sqrt(j))==0)
             k=j;

        }
        x=sqrt(num)/sqrt(k);
    }
    cout<<x<<" "<<k<<endl;
    cin>>num;
}
return 0;
}
