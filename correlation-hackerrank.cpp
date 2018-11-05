#define gc getchar_unlocked
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; 
    scanf("%d",&n);
    int i,j;
    int mat[3][n];
    for(i=0;i<n;i++)
        {
        for(j=0;j<3;j++)
         scanint(mat[j][i]);   
    }
    double sqsum[3]={0,0,0},sumsq[3]={0,0,0},prosum[3]={0,0,0};
    for(j=0;j<3;j++)
        {
        for(i=0;i<n;i++)
            {
            sqsum[j]=sqsum[j]+mat[j][i];
            sumsq[j]=sumsq[j]+mat[j][i]*mat[j][i];
        }
    }
    
    for(i=0;i<n;i++)
        {
        prosum[0]=prosum[0]+mat[0][i]*mat[1][i];
        prosum[1]=prosum[1]+mat[1][i]*mat[2][i];
        prosum[2]=prosum[2]+mat[2][i]*mat[0][i];
        
    }
    
    /*float cr[3];
    
    cr[0]=(n*prosum[0]-sqsum[0]*sqsum[1])/sqrt((n*sumsq[0]-sqsum[0]*sqsum[0])*(n*sumsq[1]-sqsum[1]*sqsum[1]) );
    cr[1]=(n*prosum[1]-sqsum[1]*sqsum[2])/sqrt((n*sumsq[2]-sqsum[2]*sqsum[2])*(n*sumsq[1]-sqsum[1]*sqsum[1]) );
    cr[2]=(n*prosum[2]-sqsum[0]*sqsum[2])/sqrt((n*sumsq[0]-sqsum[0]*sqsum[0])*(n*sumsq[2]-sqsum[2]*sqsum[2]) );*/
     double cr[3];
    long int a,b,c;
    double d,e;
    
    a=n*prosum[0]-sqsum[0]*sqsum[1];
    b=n*sumsq[0]-sqsum[0]*sqsum[0];
    c= n*sumsq[1]-sqsum[1]*sqsum[1];
    d=(float)b*c;
    e=(float)sqrt(d);
    cr[0]=(float)a/e;
    //printf("%d %d %d %f %f\n",a,b,c,d,e);
    
    a=n*prosum[1]-sqsum[2]*sqsum[1];
    b=n*sumsq[2]-sqsum[2]*sqsum[2];
    c= n*sumsq[1]-sqsum[1]*sqsum[1];
    d=(float)b*c;
    e=(float)sqrt(d);
    cr[1]=(float)a/e;
  //  printf("%d %d %d %f %f\n",a,b,c,d,e);
    
    a=n*prosum[2]-sqsum[2]*sqsum[0];
    b=n*sumsq[0]-sqsum[0]*sqsum[0];
    c= n*sumsq[2]-sqsum[2]*sqsum[2];
    d=(float)b*c;
    e=(float)sqrt(d);
    cr[2]=(float)a/e;
    //printf("%d %d %d %f %f\n",a,b,c,d,e);
    
    printf("%.2f\n%.2f\n%.2f",cr[0],cr[1],cr[2]);
   
    return 0;
}

