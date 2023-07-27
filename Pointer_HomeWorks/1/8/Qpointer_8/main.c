#include <stdio.h>
#define Size 5
#define Psize 3


void GetArray(unsigned int*,unsigned char);
void GetPattern(unsigned int*,unsigned char);
unsigned int FindPattern(unsigned int*,unsigned char,unsigned int*,unsigned char);
void PrintArray(unsigned int*,unsigned char);
int main()
{   unsigned int *ary[Size] ,pattern[Psize];
    unsigned int place;

    GetArray(ary,Size);
    GetPattern(pattern,Psize);
    place=FindPattern(ary,Size,pattern,Psize);
    if(place == -1)
        printf("not find such a pattern in this array\n\n");
    else
        printf("this pattern will start from %dth of this array\n\n",place);
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
void GetPattern(unsigned int*ptrn,unsigned char length)
{
    while (length--)
    {
         printf("\n please enter the %d num of patern :\t",Psize-length);
         scanf("%d",ptrn++);
    }
}
unsigned int FindPattern(unsigned int*arry,unsigned char alnght,unsigned int*pttrn,unsigned char plnght)
{
    unsigned char flag = 1,val1,val2;
    for(unsigned int i=0;i <= alnght - plnght;i++)
    {
        for(unsigned int j=0;j<plnght;j++)
        {
            flag=1;
            val1=*(pttrn+j);
            val2=*(arry+i+j);
            if(val1!= val2)
                flag=0;
        }
        if(flag)
            return (i+1);
    }
    return (-1);
}
void PrintArray(unsigned int*arry,unsigned char Lngth)
{
    printf("{ ");
    while (Lngth--)
        printf("%d  ",*arry++);
    printf("}");
}
