#include<bits/stdc++.h>

using namespace std;

int main(){
    int z=1;

    while(true){
        int col, row;
        cin>>row>>col;
        if(row==0 && col==0)
            break;
        char input[200][200];
        int output[200][200];
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++)
                output[i][j]=0;

        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>input[i][j];

                if(input[i][j]=='*'){
                    output[i-1][j-1]++;
                    output[i][j-1]++;
                    output[i+1][j-1]++;
                    output[i-1][j]++;
                    output[i+1][j]++;
                    output[i-1][j+1]++;
                    output[i][j+1]++;
                    output[i+1][j+1]++;


                }


            }
        }
        if(z>1)
            cout<<endl;
        printf("Field #%d:\n", z);;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                    if(input[i][j]=='*')
                        cout<<"*";
                    else
                        cout<<output[i][j];

            }
            cout<<endl;
        }
            z++;

    }
    return 0;
}
