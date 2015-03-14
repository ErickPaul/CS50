#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<cs50.h>
char* receiveInput( char *s )
{
    fgets(s,99,stdin);
    return s;
}
int main(int argc, char* argv[])
{
  if(argc!=2)
  {
    printf("key req");
    return 1;
  }
  int a[100],i;
  char k[100];
  strcpy(k,argv[1]);
  for(i=0;i<strlen(k);i++)
  {
    if(islower(k[i]))
    {
      a[i]=k[i]-97;
    }
    if(isupper(k[i]))
    {
      a[i]=k[i]-65;
    }
  }    
  i=0;  
  char p[100];
  receiveInput(p);
  char m[100];
  int j=0;
  while(p[j]!='\0')
  {
    if(i==strlen(k))
    {
      i=0;
    }  
    if(isalpha(p[j]))
    {
      if(isupper(p[j]))
      {
        m[j]=65+(p[j]-65+a[i])%26;
        i++;
      }
      if(islower(p[j]))
      {
        m[j]=97+(p[j]-97+a[i])%26;
        i++;
      }
    }
    else
    {
      m[j]=p[j];
    }
    j++;
  }
  m[--j]='\0';
  printf("%s\n",m);
  return 0;
}    
