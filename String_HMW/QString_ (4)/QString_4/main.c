#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
uint32_t strln(char *str);
int main()
{
    const char str[]="hi everyone";
    puts(str);
    printf("the length of the string is : %d",strln(str));
}
uint32_t strln(char *str)
{
    uint32_t counter=0;
    while(*str++ != NULL)
        counter++;
    return(counter);
}
