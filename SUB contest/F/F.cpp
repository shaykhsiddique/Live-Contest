#include<bits/stdc++.h>
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define find puts("I am here")
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique
 double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}


bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   double A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   double A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   double A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

double pDistance(int x, int y, int x1, int y1, int x2, int y2) {

  int A = x - x1;
  int B = y - y1;
  int C = x2 - x1;
  int D = y2 - y1;

  int dot = A * C + B * D;
  int len_sq = C * C + D * D;
  double param = -1;
  if (len_sq != EOF) //in case of 0 length line
      param = dot / (double)len_sq;

  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return sqrt(dx * dx + dy * dy);
}

int main(){
//    fli();
    int test, x1, y1, x2, y2, x3, y3, px, py;
    sfi(test);
    while(test--){
        getchar();
        scanf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)",&x1,&y1,&x2,&y2,&x3,&y3,&px,&py);
//        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<px<<" "<<py<<endl;
        if(isInside(x1, y1, x2, y2, x3, y3, px, py)){
            puts("SUB IUPC!");
        }else{
            //another
            double l1=pDistance(px,py, x1, y1, x2, y2);
            double l2=pDistance(px,py, x1, y1, x3, y3);
            double l3=pDistance(px,py, x2, y2, x3, y3);
//            debug(l1);
//            debug(l2);
//            debug(l3);
            int a=min(l1, min(l2, l3)) *10000;
            if(a%10000==0)
                printf("%d.0000\n", a/10000);
            else
                printf("%d.%d\n", a/10000,a%10000);
        }
    }
    return 0;
}
