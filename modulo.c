#include <stdio.h>
#include <math.h>

int main(void) {
  long long int t, n, c, n2, n2_4,c4, answer;
  scanf("%lld", &t);
  while(t>0){
  signed long long int n,c;
  scanf("%lld", &n);
  scanf("%lld", &c);

  n2=n*n;
  c4=pow(c,n2);
  n2_4=pow(c,4*n2);

  same  = (c4  - c ) *  ((n2_4 - c4)*4  + c4)
  diff
  

  answer =   (c * ((n2_4)/4) + c4 ) ;
  printf("%lld", answer%(1000000000 + 7));
  t--;
  }
  return 0;
}
