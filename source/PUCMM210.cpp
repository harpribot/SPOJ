#include<stdio.h>

long long unsigned A[1000010];
inline void cube()
{
   long long unsigned i,temp=0;
   for(i=1;i<=1000000;i++)
   {
      temp=(temp + i*i*i)%1000000003;
      A[i]= (A[i-1] + temp)%1000000003;
   }
}
int main()
{
   cube();
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d",&n);
     printf("%llu\n",A[n]);
   }
   return 0;
}
