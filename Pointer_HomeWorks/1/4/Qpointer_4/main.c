#include <stdio.h>
#define Size 5

void GetArray(unsigned int*,unsigned char);
void ReverseArray(unsigned int*,unsigned char);
void PrintArray(unsigned int*,unsigned char);
int main()
{   unsigned int *ary[Size];
    unsigned int Num=0;
    printf("\n please enter the array\n ");
    GetArray(ary,Size);
    printf("\n\n after reverse : ");
    ReverseArray(ary,Size);
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
void ReverseArray(unsigned int*arry,unsigned char lnght)
{   unsigned int temp;
    unsigned char len=lnght/2;
    unsigned int *probe=arry+lnght-1;
    while(len--)
    {
        temp=*arry;
        *arry=*probe;
        *probe=temp;
        arry++;
        probe--;
    }
}
void PrintArray(unsigned int*arry,unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}\n");
}

