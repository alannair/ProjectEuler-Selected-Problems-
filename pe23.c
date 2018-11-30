#include <stdio.h>
#include <math.h>
#define lim 28123

void init(int arr[],int size)//initialize to zero array
{
  for(int i=0;i<lim;++i)
  {
    arr[i]=0;
  }
}

void printarr(int arr[], int size)
{
  for(int i=0;i<size;++i)
      if(arr[i]) printf("%d ",i);
  printf("\n");

}

int divsum(int n)
{
  int sum=n+1;
  double rt=(sqrt(n));
  for(int i=2;i<=rt;++i)
    {if (n%i==0&&i!=rt)
      {sum+=(i+n/i);}
    if (n%i==0&&i==rt)
      {sum+=rt;}
    }

  return sum;
}

void find_abundant(int arr[],int size)
{
  for(int i=2;i<size;++i)
    if(divsum(i)>2*i)
    arr[i]=1  ;
}

void find_sum(int arr[], int sum[], int size)
{
  for(int i=0;i<size/2+1;++i)
  {
    if(arr[i]==0) continue;
    for(int j=i;j<size-i;++j)
    {
      if(arr[j]==0) continue;
      sum[i+j]=1;
    }
  }
}

int answer(int arr[],int size)
{
  int ans=0;
  for(int i=1;i<size;++i)
    if(arr[i]==0) ans+=i;
  return ans;
}

int main()
{
  int abundant[lim];//stores all abundant numbers below lim 0=not abundant, 1=abundant
  int sum[lim];//0=cant be expressed as sum, 1=can be expressed as sum of 2 abundant numbers
  int *ptr=NULL;

  init(abundant,lim);
  init(sum,lim);

  find_abundant(abundant,lim);
  find_sum(abundant,sum,lim);
  int finalsum=answer(sum,lim);

  printf("%d\n",finalsum);
  /*printarr(abundant,lim);
  printarr(sum,lim);*/

  return 0;
}
