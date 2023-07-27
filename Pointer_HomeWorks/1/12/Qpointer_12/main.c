#include <stdio.h>
#include <math.h>
#define Size 5


void GetArray(unsigned int*[Size],unsigned char);
void LowtoHigh(unsigned int*[Size],unsigned char);
void PrintArray(unsigned int*[Size],unsigned char);
unsigned int BinarySerach(unsigned int*[Size],unsigned int,unsigned int,unsigned int);
int main()
{   unsigned int *ary[Size];
    unsigned int num,min,max;
    unsigned char index;
    GetArray(ary,Size);
    LowtoHigh(ary,Size);
    printf("\n\n the array after sorting low to high :\n\n");
    PrintArray(ary,Size);
    printf("\n\n please enter the number :\t\t");
    scanf("%d",&num);
    index=BinarySerach(ary,0,Size,num);
    printf("\n\n this number is in %dth of the array \n\n",index+1);

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
unsigned int BinarySerach(unsigned int*arry[Size],unsigned int min,unsigned int max,unsigned int num)
{
    unsigned char val =*((max+min)/2+arry);
    unsigned char mid=(max+min)/2;
    if(num==val)
        return(mid);
    else if(num <val)
        return (BinarySerach(arry,min,mid,num));
    else if(num > val)
        return (BinarySerach(arry,mid,max,num));
}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
