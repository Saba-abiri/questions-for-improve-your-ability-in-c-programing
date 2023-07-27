#include <stdio.h>
#include <math.h>
#define Size 5


void GetArray(unsigned int*[Size],unsigned char);
void LowtoHigh(unsigned int*[Size],unsigned char);
void HightoLow(unsigned int*[Size],unsigned char);
void PrintArray(unsigned int*[Size],unsigned char);
int main()
{   unsigned int *ary[Size];

    GetArray(ary,Size);
    LowtoHigh(ary,Size);
    printf("\n\n the array after sorting low to high :\n\n");
    PrintArray(ary,Size);

    HightoLow(ary,Size);
    printf("\n\n the array after sorting high to low :\n\n");
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

void LowtoHigh(unsigned int*arry[Size],unsigned char lnght)
{
    unsigned int temp;
    unsigned int val1,val2;
    for(unsigned int i=0;i < lnght;i++)
    {
        for(unsigned int j=0;j < 4-i;j++)
        {   val1=*(arry+j);
            val2=*(arry+1+j);
            if( val1 > val2 )
            {
                temp=*(arry+j);
                *(arry+j)= *(arry+j+1);
                *(arry+j+1)=temp;
            }
        }
    }
}
void HightoLow(unsigned int*arry[Size],unsigned char lnght)
{
    unsigned int temp;
    unsigned int val1,val2;
    for(unsigned int i=0;i < lnght;i++)
    {
        for(unsigned int j=0;j < 4-i;j++)
        {   val1=*(arry+j);
            val2=*(arry+1+j);
            if( val1 < val2 )
            {
                temp=*(arry+j);
                *(arry+j)= *(arry+j+1);
                *(arry+j+1)=temp;
            }
        }
    }
}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
