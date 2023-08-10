#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void lowtoup(char **str, uint8_t len);
void strshow(char **str, uint8_t len);
uint8_t binsrch(char ** str,uint8_t min,uint8_t max,char *ptrn ,uint8_t len);
int main()
{
  char *str[6]={"ali", "saba", "amir","sina","zahra","nika"};
  uint8_t len=sizeof(str)/sizeof(str[0]);
  strshow(str,len);
  lowtoup(str,len);
  strshow(str,len);
  uint8_t ans=binsrch(str,0,5,"zahra",len);
  printf("the index is %d\n\n",ans);
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
                char temp[20];

                strcpy(temp,str+j);
                strcpy(str+j, str+j+1);
                strcpy(str+j+1,temp);
            }

        }
}
uint8_t binsrch(char ** str,uint8_t min,uint8_t max,char *ptrn ,uint8_t len)
{
    uint8_t mid=(max+min)/2;
    if(mid!=min)
    {
        int8_t Res=strcmp(ptrn,*(str+mid));
        if(Res==0)
            return (mid);
        else if(Res<0)
            return(binsrch(str,min,mid,ptrn,len));
        else if(Res>0)
            return(binsrch(str,mid,max,ptrn,len));
    }
    else
    {
        if(!strcmp(ptrn,*(str+max)))
            return(max);
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
