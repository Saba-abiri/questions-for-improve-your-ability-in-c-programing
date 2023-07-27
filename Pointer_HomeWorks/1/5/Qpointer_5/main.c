#include <stdio.h>
#include <stdint.h>
#define Size 3

void GetArray(unsigned int*,unsigned char);
void ReverseArray(unsigned int*,unsigned int*,unsigned char);
void PrintArray(unsigned int*,unsigned char);
int main()
{   unsigned int *ary1[Size],*ary2[Size];
    unsigned int Num=0;
    printf("\n please enter the array\n ");
    GetArray(ary1,Size);
    ReverseArray(ary1,ary2,Size);
    printf("\n\n first array : ");
    PrintArray(ary1,Size);
    printf("\n\n second array : ");
    PrintArray(ary2,Size);
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
void ReverseArray(unsigned int*arry1,unsigned int*arry2,unsigned char lnght)
{
    uint32_t *prob=lnght - 1 + arry2;
    while (lnght--)
       *prob-- = *arry1++;

}
void PrintArray(unsigned int*arry,unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}\n");
}

