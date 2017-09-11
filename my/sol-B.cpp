#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
string number;
cin>>number;
while(1){
    if(number[1]=='x'){
         ll b=(ll)strtol(number.c_str(), 0, 16);
         cout <<dec<<b<<endl;
    }
    else{


  ll b = atoi(number.c_str());
  if(b<0)
    break;
  cout<<"0x"<<hex<<uppercase<<b<<endl;
    }
    cin>>number;
}

return 0;
}
