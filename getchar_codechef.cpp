#define gc getchar_unlocked
#include <iostream>
#include <stdio.h> 

using namespace std;

void scanint(int &x)
{
     register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=x*(-1);

}

int main()
{
	int m,n,i,t,e=0;
	int negindic=1, posindic=1,common_indic=1,xcent=0,ycent=0,dum_max_str,max_str=0;
	scanf("%d %d",&m, &n);
	
	int cord_weight[m][n];

	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanint(cord_weight[i][j]);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; i < n; ++j)
		{

			common_indic=1;
			posindic=1;
			negindic=1;
			dum_max_str=0;

			while(common_indic)
			{
				while(posindic)
				{
					if ( (cord_weight[i+1][j+1] + cord_weight[i-1][j-1]) < 0 || i+1>m || j+1 > n || i-1 < 0 || j-1 < 0 )
						 { posindic=0 ; }
						if (posindic==0) break;
					dum_max_str = dum_max_str + cord_weight[i+1][j+1] + cord_weight[i-1][j-1] ;
				}

				while(negindic)
				{
					if ( (cord_weight[i+1][j-1] + cord_weight[i-1][j+1]) < 0 || i+1>m || j+1 > n || i-1 < 0 || j-1 < 0 )
						 { negindic=0 ; }
						if (negindic==0) break;
					dum_max_str = dum_max_str + cord_weight[i+1][j+1] + cord_weight[i-1][j-1] ; 
				}

				if (dum_max_str>max_str)
				{
					max_str=dum_max_str;
				}

				common_indic= (posindic + negindic);
			}




			
		}
	}
printf("%d\n", max_str);
return 0;
}