#include<bits/stdc++.h>
using namespace std;
int main(){
int s,n[101],h[101][101],i,j,k;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

scanf("%d", &s);
for(i=0; i<s; i++){
        scanf("%d", &n[i]);
    for(j=0; j<n[i]; j++){
        scanf("%d", &h[i][j]);
    }
}
int found,f1;
for(i=0; i<s; i++){
        found=1;
    for(j=0; j<n[i]; j++){
            if(n[i]%2==1){
        if(h[i][0]==1){

            for(k=n[i]/2-1; k>=1; k--){
                if(h[i][k]-h[i][k-1]==1){
                    f1=0;
                }
                else{
                    f1=1;
                    break;
                }
            }
            if(f1==0){
                for(k=n[i]/2; k<n[i]-1; k++){
                    if(h[i][k]-h[i][k+1]==1){
                            found=1;
                    }
                    else{
                        found=0;
                        break;
                    }
                }
            }
            else{
                found=0;
            }

        }
        else{
            found=0;
            break;
        }
            }
            else{
                found=0;
            }
    }
    if(found==0){
        printf("no\n");
    }
    else{
        printf("yes\n");
    }
}
return 0;
}
