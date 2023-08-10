#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void uptolow(char **str, uint8_t len);
void lowtoup(char **str, uint8_t len);
void strshow(char **str, uint8_t len);
int main()
{
  char *str[3]={"aaa", "abc", "ccc"};
  uint8_t len=sizeof(str)/sizeof(str[0]);
  strshow(str,len);
  uptolow(str,len);
  printf("after sorting up to down\n");
  strshow(str,len);
  lowtoup(str,len);
  printf("after sorting down to up\n");
  strshow(str,len);
}

void uptolow(char **str, uint8_t len)
{
   for(int i=0;i<len;i++)
        for(int j=0;j<len-i-1;j++)
        {
            char *st1=*(str+j);
            char *st2=*(str+j+1);
            if(strcmp(st1,st2)<0)
            {
                char temp[20]="Salam";

                strcpy(temp,str+j);
                strcpy(str+j, str+j+1);
                strcpy(str+j+1,temp);
            }

        }
}
void lowtoup(char **str, uint8_t len)
{
    for(int i=0;i<len;i++)
        for(int j=0;j<len-i-1;j++)
        {
            char *st1=*(str+j);
            char *st2=*(str+j+1);
            if(strcmp(st1,st2)>0)
            {
                char temp[20]="Salam";

                strcpy(temp,str+j);
                strcpy(str+j, str+j+1);
                strcpy(str+j+1,temp);
            }

        }
}
void strshow(char ** str, uint8_t len)
{
    printf("\n\n the array is :\n{\n ");
    for(int i=0;i<len;i++)
    {
        puts(*(str+i));
        printf(" ");
    }
    printf("   }\n\n");
}
