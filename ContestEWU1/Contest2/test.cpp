#include<iostream>

using namespace std;

int main(){
    int c, i, j, k, C, N[20], a[10], b[10];
    cin>>C;
    for(c=0; c<C; c++){
        cin>>N[c];
    }
    for(c=0; c<C; c++){
    for(i=0, j=1; i<N[c]; i++, j++){
        a[i]=j;
    }
    }
    for(c=0; c<C; c++){
        for(k=0; k<=9; k++){
            for(i=0; i<N[c]; i++){
                if(a[i]==k){
                    b[k]=1;
                    break;
                }
                else
                    b[k]=0;
            }
            cout<<b[k];
        }
        cout<<endl;
    }




    return 0;
}
