#include <stdio.h>
#include <math.h>

int isprime(int number)
{
    if(number<2)
        return 0;
    if(number==2)
        return 1;
    if(number%2==0)
        return 0;
    for(int i=3;i<=sqrt(number);i += 2)
    {
        if(number%i==0)
            return 0;
    }
    return 1;
}

int check(int n, int digits)
{
  if(!isprime(n)) return 0;

  for(int times=0; times<digits;++times)
  {
    n = (n%10)*pow(10,digits-1) + n/10;
    if(!isprime(n)) return 0;
  }

  return 1;
}

int main()
{

  int count=1, digit=1;

  for(int i=3; i<1000000;i+=2)
  {
    if(i>10) digit=2;
      if(i>100) digit=3;
        if(i>1000) digit=4;
          if(i>10000) digit=5;
            if(i>100000) digit=6;
    if(check(i,digit)) ++count;

  }
  printf("%d\n",count );
  return 0;
}
