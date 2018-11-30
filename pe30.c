#include <stdio.h>
#include <math.h>

int main()
{
int sum=0;
  for (int i=2; i<=5*pow(9,5); ++i)
  {
    int fifthsum=0, j=i;
    while(j)
    {
      fifthsum+=pow(j%10,5);
      j/=10;
    }

    if(fifthsum==i) sum+=i;
  }

  printf("%d\n",sum );
  return 0;
}
