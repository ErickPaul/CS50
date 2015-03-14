/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>

int main()
{
    // TODO
    int i=0,j,prev=0;
    char title[8];
    FILE* file = fopen("card.raw", "r");
    uint8_t buffer[512];
    while(1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
             prev=1;
             sprintf(title,"%03d.jpg",i);
             FILE* image = fopen(title,"a");
             fwrite(buffer,512,1,image);
             fclose(image);
             i++;
        }
        else if(prev==1)
        {
            FILE* image = fopen(title,"a");
            fwrite(buffer,512,1,image);
            fclose(image);
        }
        j=fread(buffer,512,1,file);
        if(j==0)
        {
            break;
        }
    }
    return 0;
}
