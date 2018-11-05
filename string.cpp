#include <iostream>
#include <string>
using namespace std;

int main ()
{
  int t, k, n, att, rem, i, num;
  long int v;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%ld",&v);
    string str_arr[n];
    for( i = 0; i < n; i++;)
    {
        getline (cin, str_arr[i]);
    }
    num = (v-1)*k;
    rem = num%n;
    att = k - rem;
    if(att >= k)
    {
        string fin = "Case #" + to_string(t) + " " ;
        for(i=0; i< k; i++;) 
        {
            fin = fin + str_arr[i+rem];
        }
        fin = fin + "\0";
        printf("%s",fin);
    }
    else
    {
        int kk = k - att;
        string fin = "Case #" + to_string(t) + " ";
        for(i=0 ; i < kk ; i++;) 
        {
            fin = fin + str_arr[i];
        }
        for( ; i < k ; i++;)  
       { 
            fin = fin + str_arr[i+rem];
        }
        fin = fin + "\0";
        printf("%s",fin);
    }
  }
return 0;
}
