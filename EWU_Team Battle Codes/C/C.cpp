#include<bits/stdc++.h>
using namespace std;
#define con (acos(-1)/6)
int main(){

int test,a;
double side,p,area;
scanf("%d",&test);
while(test--){
    scanf("%d",&a);
p=a/2.0;
side=p/sin(con);
area=3*(side*side)*sin((2*con));
//cout<<side<<"  "<<p<<endl;

printf("%.6f\n",(double)area);


}

return 0;




}
