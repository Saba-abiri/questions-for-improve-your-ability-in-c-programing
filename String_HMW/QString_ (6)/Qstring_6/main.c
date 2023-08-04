#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
uint32_t strln(char *str);
char *findpattern(char *src, char *ptrn,uint32_t srcln ,uint32_t ptrnln);
void RepStr(char *ptrn,char *adrs);
int main()
{
    const char srcstr[]="abcdefghij";
    const char ptrnstr[]="fgh";
    const char Repstr[]="FGH";
    char * adrs =findpattern(srcstr,ptrnstr,strln(srcstr),strln(ptrnstr));
    if(adrs)
    {
        printf("the string is :");
        puts(srcstr);
        printf("the pattern is :");
        puts(ptrnstr);
        RepStr(Repstr,adrs);
        puts(srcstr);
    }
    else
        printf("not find");

}
char *findpattern(char *src, char *ptrn,uint32_t srcln ,uint32_t ptrnln)
{   uint32_t flag;
    for(uint32_t i=0;i<srcln-ptrnln+1;i++)
        {
            flag = 1;
            for(uint32_t j=0;j<ptrnln;j++)
                if(*(src+i+j)!=*(ptrn+j))
                    flag =0;
            if(flag)
                return(src+i);
        }
    return(NULL);
}
uint32_t strln(char *str)
{
    uint32_t counter=0;
    while(*str++ != NULL)
        counter++;
    return(counter);
}
void RepStr(char *ptrn,char *adrs)
{
    while(*ptrn != NULL)
        *adrs++=*ptrn++;
}
