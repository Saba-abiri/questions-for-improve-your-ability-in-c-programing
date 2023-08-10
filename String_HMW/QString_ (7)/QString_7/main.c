#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int8_t strcomp(char * str1,char * str2);
int main()
{
    char str1[]="abcd";
    char str2[]="abce";
    int8_t res=strcomp(str1,str2);
    switch (res)
    {
    case 1:
        printf("first string is bigger than second\n\n");
        break;
    case -1:
        printf("second string is bigger than first\n\n");
        break;
    case 0:
        printf("first and second string are equal\n\n");
    }

}
int8_t strcomp(char * str1,char * str2)
{
    while(*str1)
    {
        if(*str1 != *str2)
        {
            if(*str1 > *str2)
                return(1);
            else if(*str1 < *str2)
                return(-1);
        }
        str1++;
        str2++;
    }
    return(0);
}
