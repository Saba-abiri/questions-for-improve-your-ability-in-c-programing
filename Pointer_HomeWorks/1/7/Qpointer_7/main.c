#include <stdio.h>
#include <stdint.h>
#define Size 3



void GetArray(unsigned int*,unsigned char);
int ComArry(unsigned int*,unsigned char,unsigned int*);
void PrintArray(unsigned int*,unsigned char);
int main()
{   unsigned int *ary1[Size] ,*ary2[Size] ;
    unsigned int copmarray;

    GetArray(ary1,Size);
    GetArray(ary2,Size);
    copmarray=ComArry(ary1,Size,ary2);
    printf("result is %d \n\n",copmarray);
    PrintArray(ary1,Size);
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

int ComArry(unsigned int*arry1,unsigned char len,unsigned int*arry2)
{
    while(len--)
    {
        int32_t temp=*arry1++ -*arry2++;
        if(temp)
            return(temp);
    }
    return(0);
}
void PrintArray(unsigned int*arry,unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}\n\n");
}
