#include <stdio.h>
#define Size 5

void GetArray(unsigned int*[Size],unsigned char);
void GetNum(unsigned int *);
void ChangeNum(unsigned int*[Size],unsigned int,unsigned char);
void PrintArray(unsigned int*[Size],unsigned char);
int main()
{   unsigned int *ary[Size];
    unsigned int Num=0;

    GetArray(ary,Size);
    GetNum(&Num);
    ChangeNum(ary,Num,Size);
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
void ChangeNum(unsigned int*arry[Size],unsigned int Num,unsigned char lnght)
{
    while (lnght--)
        *arry++=Num;

}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
