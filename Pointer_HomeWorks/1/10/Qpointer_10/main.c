#include <stdio.h>
#define Size 5

void GetArray(unsigned int*[Size],unsigned char);
void GetNum(unsigned int *);
unsigned int FindNum(unsigned int*[Size],unsigned int*,unsigned char);
void DelNum(unsigned int*[Size],unsigned int,unsigned char);
void PrintArray(unsigned int*[Size],unsigned char);
int main()
{   unsigned int *ary[Size];
    unsigned int * Num=0,place;

    GetArray(ary,Size);
    GetNum(&Num);
    place=FindNum(ary,&Num,Size);
    if(place == -1)
        printf("not find such a number in this array\n\n");
    else
    {
        printf("this number is in %dth of this array\n\n",place);
        DelNum(ary,place-1,Size);
    }
    PrintArray(ary,Size);
    return 0;
}
void GetArray(unsigned int*arry[Size],unsigned char Lngth)
{
    while (Lngth--)
    {
         printf("\n please enter the %d num of array :\t",Size-Lngth);
         scanf("%d",arry++);
    }

}
void GetNum(unsigned int *Num)
{
    printf("\n please enter the Num :\t");
    scanf("%d",Num);
    printf("\n  Num :\t%d\n",*Num);
}
unsigned int FindNum(unsigned int*arry[Size],unsigned int *number,unsigned char lnght)
{
    int value;
    for(unsigned int i=0;i<lnght;i++)
    {
        value=arry[i];
        if(*number == value)
            return (i+1);
    }
        return(-1);


}
void DelNum(unsigned int*ary[Size],unsigned int index,unsigned char lenght)
{
      for(int i=index ; i<lenght-1;i++)
               *(ary+i)=*(ary+i+1);
            *(ary+lenght-1)=NULL;


}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
