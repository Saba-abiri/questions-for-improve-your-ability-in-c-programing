#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
uint32_t strln(char *str);
char *findpattern(char *src, char *ptrn,uint32_t srcln ,uint32_t ptrnln);
int main()
{
    const char srcstr[]="abcdefghij";
    const char ptrnstr[]="fgh";
    char * adrs =findpattern(srcstr,ptrnstr,strln(srcstr),strln(ptrnstr));
    char * place;
    if(adrs)
    {
        place=(adrs-srcstr)/sizeof(srcstr[0])+1;
        printf("the string is :");
        puts(srcstr);
        printf("the pattern is :");
        puts(ptrnstr);
        printf("\nthe address is :%x   \nand this is %dth character and first character is: %c\n\n",adrs,place,*adrs);
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
