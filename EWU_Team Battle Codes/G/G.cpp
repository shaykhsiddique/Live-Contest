#include<bits/stdc++.h>
using namespace std;
int conn[20];
double dis(int x1,int y1,int x2,int y2){

double d;
int x,y;
x=x2-x1;
y=y2-y1;
d=sqrt((x*x)+(y*y));

return d;
}
int main(){
memset(conn,0,sizeof(conn));
int n,x[20],y[20];
double total=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d%d",&x[i],&y[i]);
}
int j=0;
int t=n;
while(t--){
        if(conn[j]==0)
for(int i=0;i<n;i++){
    if(conn[i]==0){
    if(mindis>dis(x[j],y[j],x[i],y[i])){
        mindis=dis;
        lessp=i;

    }

    }
}
else j++;
}
return 0;
}
