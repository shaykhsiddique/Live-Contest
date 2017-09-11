#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    string input;
    cin>>test;
    cin.ignore();
    for(int i=1; i<=test; i++){

        getline(cin, input);
        int k=0, kk=0;
        bool check=false;
        for(int j=0; j<input.size(); j++){
            if(input[j]>47&&input[j]<58&&j<2){
                if(input[j]=='1'&&input[j+1]=='0'){
                    k=10;
                    check=true;
                }
                else if(!check){
                    k=input[j]-48;

                }
            }
            if(input[j]>47&&input[j]<58&&j>2){
                    kk=input[j]-48;
            }
        }
        double j= (k*0.5)+(kk*0.05);
        cout<<"Case "<<i<<": "<<j<<endl;
    }
    return 0;
}
