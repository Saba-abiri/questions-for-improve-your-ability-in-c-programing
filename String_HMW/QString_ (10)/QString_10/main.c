#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
uint8_t findstr(char **str,char *patrn,uint8_t len);
int main()
{
    char * str[4]={"saba", "ali", "fariba" ,"sina"};
    uint8_t len=sizeof(str)/sizeof(str[0]);
    printf("\nthe index is %d\n\n",findstr(str,"ali",len));
}

uint8_t findstr(char **str,char *patrn,uint8_t len)
{
    uint8_t counter=0;
    while(counter<len)
    {
        if(!strcmp(patrn,*(str+counter)))
            return(counter);
            counter++;
    }
    return('\0');
}
