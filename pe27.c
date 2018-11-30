#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_test(int n) //1 if prime
{

  if(n<0) n*=-1;
	int i;
	for(i=2; i<=sqrt(n); i++)
	{
		if(n%i!=0)
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
  int a_c=0, b_c=0, s1_max=0, s1=0;

  for(int a=0; a<1000; ++a)
  {
    printf("%d %d %d %d\n",a,s1_max,a_c,b_c );
    for(int b=1; b<1000; b+=2)
    {
      s1=0;
      for(int n=0;1;++n)
      {

        if(prime_test(n*n +b+ a*n) ) ++s1;
        else break;
      }
      if(s1>s1_max) {a_c=a; b_c=b; s1_max = s1;}

      s1=0;
      for(int n=0;1;++n)
      {

        if(prime_test(n*n -b+ a*n) ) ++s1;
        else break;
      }
      if(s1>s1_max) {a_c=a; b_c=b; s1_max = s1;}

      s1=0;
      for(int n=0;1;++n)
      {

        if(prime_test(n*n +b- a*n) ) ++s1;
        else break;
      }
      if(s1>s1_max) {a_c=a; b_c=b; s1_max = s1;}

      s1=0;
      for(int n=0;1;++n)
      {

        if(prime_test(n*n -b- a*n) ) ++s1;
        else break;
      }
      if(s1>s1_max) {a_c=a; b_c=b; s1_max = s1;}
    }
  }

  printf("%ld\n",((long)a_c)*((long)b_c) );
  return 0;
}
