#include <stdio.h>
#include <stdint.h>
#define Size 5


void GetArray(unsigned int*,unsigned char);
void GetNum(unsigned int *);
unsigned int FindNum(unsigned int*,unsigned int*,unsigned char);
void PrintArray(unsigned int*,unsigned char);
int main()
{   unsigned int *ary[Size];
    unsigned int * Num=0,place;

    GetArray(ary,Size);
    GetNum(&Num);
    place=FindNum(ary,&Num,Size);
    if(place == -1)
        printf("not find such a number in this array\n\n");
    else
        printf("this number is in %dth of this array\n\n",place);
    PrintArray(ary,Size);
    return 0;
}
void GetArray(unsigned int*arry,unsigned char Lngth)
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
unsigned int FindNum(unsigned int*arry,unsigned int *number,unsigned char lnght)
{
    int *value;
    uint8_t ln=lnght;
    while(lnght--)
    {
        value=*(arry++);
        if(*number == value)
            return (ln-lnght);
    }
        return(-1);


}
void PrintArray(unsigned int*arry,unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
