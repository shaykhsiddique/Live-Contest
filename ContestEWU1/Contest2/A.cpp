#include<bits/stdc++.h>

using namespace std;

int main(){

    int test, n, d;
    cin>>test;

    for(int i=1; i<=test; i++){
        cin>>n;
        int co_zero=0, co_one=0, co_two=0, co_three=0, co_four=0, co_five=0, co_six=0, co_seven=0, co_eight=0, co_nine=0;
        for(int j=1; j<=n; j++){
                d=j;
            while(d!=0){
                    int l=d%10;
                switch(l){
                case 1:
                    co_one++;
                    break;
                case 2:
                    co_two++;
                    break;
                case 3:
                    co_three++;
                    break;
                case 4:
                    co_four++;
                    break;
                case 5:
                    co_five++;
                    break;
                case 6:
                    co_six++;
                    break;
                case 7:
                    co_seven++;
                    break;
                case 8:
                    co_eight++;
                    break;
                case 9:
                    co_nine++;
                    break;
                case 0:
                    co_zero++;
                    break;

            }

             d/=10;
        }

    }

        printf("%d %d %d %d %d %d %d %d %d %d\n", co_zero, co_one, co_two, co_three, co_four, co_five, co_six, co_seven, co_eight, co_nine);
    }

    return 0;
}
