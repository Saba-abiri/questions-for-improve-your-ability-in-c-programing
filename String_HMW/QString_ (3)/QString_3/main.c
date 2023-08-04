#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char * findchar(char *str ,char ch);
int main()
{
    char str[]="name family";
    char CH='f';
    char * address=findchar(str,CH);
    printf("the string is : ");
    puts(str);
    printf("the address of %c is : %x \t %xth character\n\n\n ",CH,address,(address-str)/sizeof(str[0]));
}
char * findchar(char *str ,char ch)
{
    while(*str++ != ch);
        return (str--);

}
