#include <stdio.h>
#define Size 3

void GetArray(unsigned int*[Size],unsigned char);
void ChangeArray(unsigned int*[Size],unsigned int*[Size],unsigned char);
void PrintArray(unsigned int*[Size],unsigned char);
int main()
{   unsigned int *ary1[Size], *ary2[Size];
    unsigned int Num=0;
    printf("\n please enter the first array\n ");
    GetArray(ary1,Size);
    printf("\n\n please enter the second array\n ");
    GetArray(ary2,Size);
    ChangeArray(ary1,ary2,Size);
    printf("\n\n first array after change : ");
    PrintArray(ary1,Size);
    printf("\n\n second array after change : ");
    PrintArray(ary2,Size);
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
void ChangeArray(unsigned int*arry1[Size],unsigned int*arry2[Size],unsigned char lnght)
{   unsigned int index;
    printf("\n\nplease enter Index of array 1 that you want to change :\t");
    scanf("%d",&index);
    index--;
    if(index>=lnght)
        printf("\n\nthe num you have entered was not on correct range !!!\n\n");
    while (lnght-- - index)
        *(arry1++ + index) =*(arry2++ + index);

}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}\n");
}
