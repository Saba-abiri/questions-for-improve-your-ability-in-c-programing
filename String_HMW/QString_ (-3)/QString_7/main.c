#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
uint32_t Compstr(char * str1,char * str2);
int main()
{
    const char str1[]="salam";
    const char str2[]="saalm";
    printf("compare result is :%d",Compstr(str1,str2));
}
uint32_t Compstr(char * str1,char * str2)
{
    while(*str1!=NULL)
    {
        if(*str1 != *str2)
            return(*str1 - *str2);
        str1++;
        str2++;
    }
    return(0);
}
