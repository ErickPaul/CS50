/*#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main()
{
    float amt;
    int ct1=0,ct2=0,ct3=0,ct4=0,cent_amount;
    printf("how much i owed\n");
    while(1)
    {
      amt=GetFloat();
      if(amt>=0)
      {break;
      }
      if(amt<0)
      {
      printf("how much i owed?\n");
      }
    }
    cent_amount = (int)round(amt*100);
    while(cent_amount-25>=0)
    {cent_amount=cent_amount-25;
    ct1++;
    }
    while(cent_amount-10>=0)
    {cent_amount=cent_amount-10;
     ct2++;
     }
     while(cent_amount-5>=0)
     {
     cent_amount=cent_amount-5;
     ct3++;
     }
     while(cent_amount-1>=0)
     {cent_amount=cent_amount-1;
     ct4++;
     }
     printf("%d\n",ct1+ct2+ct3+ct4);
     return 0;
  }
*/


#include<stdio.h>
#include<cs50.h>
int main()
{
  float n;
  int count=0,p;
  printf("O hai!  How much change is owed?\n");
  n=GetFloat();
  while(n<0)
  {
    printf("How much change is owed?\n");
    n=GetFloat();
  }
  p=n*100;
  while(p>=25)
  {
    count=count+p/25;
    p=p%25;
  }
  while(p>=10)
  {
    count=count+p/10;
    p=p%10;
  }
  while(p>=5)
  {
    count=count+p/5;
    p=p%5;
  } 
  if(p>=1)
  {
    count=count+p;
  }
  printf("%d\n",count);
  return 0;
}  
