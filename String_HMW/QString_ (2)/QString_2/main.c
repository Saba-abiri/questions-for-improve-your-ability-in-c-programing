#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void AppendStr(char * str1,char * str2);
int main()
{
    char str_first[15]="name";
    static const char str_second[]="family";
    AppendStr(str_first,str_second);
    puts(str_first);
}
void AppendStr(char * str1,char * str2)
{
    while(*(++str1)!= NULL);
    *str1++ =' ';
    while(*str2 != NULL)
        *str1++=*str2++;
    *str1 = NULL;
}
