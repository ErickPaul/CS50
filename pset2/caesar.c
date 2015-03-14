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
  int k;
  if (argc != 2)
  {
    printf("key req\n");
    return 1;
  }     
  k=atoi(argv[1]);
  char c[100];
  receiveInput(c);
  int length = strlen(c);
  c[length-1]='\0';
  char m[100];
  int j=0;
  while(c[j]!='\0')
  {
    if(isalpha(c[j]))
    {
      int z=c[j];
      if(isupper(c[j]))
      m[j]=65+(z-65+k)%26;
      if(islower(c[j]))
      m[j]=97+(z-97+k)%26;
    }
    else
    {
      m[j]=c[j];
    }
    j++;
  }
  m[j]='\0';
  printf("%s\n",m);
  return 0;
}    
   

