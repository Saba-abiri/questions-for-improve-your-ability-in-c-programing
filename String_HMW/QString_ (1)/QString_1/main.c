#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void strApend(char * srcst,char * copyst);
int main()
{
    char  srcstr[15]="name";
    char  copystr[]="family";
    strApend(srcstr,copystr);
    puts(srcstr);
}
void strApend(char * srcst,char * copyst)
{
    while(*copyst != NULL)
        *srcst++ = *copyst++;
    *srcst=NULL;
}
