#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint32_t *findstr(char **str,char *text,uint8_t len);
int main()
{
    char text[]="this is a text which contain the names of ali , elham , saba , maryam , sina";
    char *str[]={"saba","ali","sina","maryam","elham"};
    uint8_t len=sizeof(str)/sizeof(str[0]);

}
uint32_t *findstr(char **str,char *text,uint8_t len)
{
    while(text++)
    {
        for(uint8_t i=0;i<len;i++)
            if(!strcmp(text,*(str+i)))
        {
            uint32_t ans[2]={text,i};
            return(ans);
        }
    }
    return('\0');
}
