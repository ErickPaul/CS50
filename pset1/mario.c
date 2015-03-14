#include<stdio.h>
#include<cs50.h>
int main()
{
  int i=1,j,n;
  printf("Height:");
  n=GetInt();
  while(n<0||n>23)
  {
    printf("Retry:");
    n=GetInt();  
  }
  while(i<=n)
  {
      j=0;
      while(j<n-i)
      {
          printf(" ");
          j++;
      }
      while(j<=n)
      {
          printf("#");
          j++;
      }
  i++;
  printf("\n");
  }  
  return 0;
}        
          
