#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void strcopy(char * srcst,char * copyst);
int main()
{
    char  srcstr[15]="name";
    char  copystr[]="family";
    strcopy(srcstr,copystr);
    puts(srcstr);
}
void strcopy(char * srcst,char * copyst)
{
    while(*copyst != NULL)
        *srcst++ = *copyst++;
    *srcst=NULL;
}
