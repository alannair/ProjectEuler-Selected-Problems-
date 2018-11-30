#include <stdio.h>
//#include <math.h>

int fact(int i)
{
  switch(i)
  {
    case 0:
    case 1: return 1;
    case 2: return 2;
    case 3: return 6;
    case 4: return 24;
    case 5: return 120;
    case 6: return 720;
    case 7: return 720*7;
    case 8: return 720*56;
    case 9: return 720*56*9;


  }
}

int main()
{
int sum=0;
  for (int i=3; i<=5*fact(9); ++i)
  {
    int factsum=0, j=i;
    while(j)
    {
      factsum+=fact(j%10);
      j/=10;
    }

    if(factsum==i) sum+=i;
  }

  printf("%d\n",sum );
  return 0;
}
