#include<stdio.h>
#define lim 1000000

int array[lim];

int collatz(int n)
{
if(n%2==0) return n/2;
else return 3*n+1;
}

int maxindex(void)
{
int index=0,val=0;

for(int i=1;i<lim;++i)
    if(array[i]>val)
        {val=array[i];index=i;}

return index;
}

int f(int n)
{
    if(n==1||n==2) return n;
    if (n<lim)
        {
        if(array[n]==0) array[n]=1+f(collatz(n));
        return array[n];
        }
    else return 1+f(collatz(n));
}

int main()
{
for(int i=0;i<lim;++i)
    array[i]=0;
array[1]=1;
array[2]=2;

for(int i=1;i<lim;++i)
    f(i);

printf("%d",maxindex());

return 0;
}
