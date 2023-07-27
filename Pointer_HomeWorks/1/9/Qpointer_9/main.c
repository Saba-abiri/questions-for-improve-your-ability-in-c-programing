#include <stdio.h>
#include <math.h>
#define Size 10


unsigned int GetArray(unsigned int*[Size],unsigned char);
void AddNum(unsigned int*[Size],unsigned char,unsigned int);
void PrintArray(unsigned int*[Size],unsigned char,unsigned int);
int main()
{   unsigned int *ary[Size];
    unsigned int count=0;
    count=GetArray(ary,Size);
    AddNum(ary,Size,count-1);
    PrintArray(ary,Size,count);

    return 0;
}
unsigned int GetArray(unsigned int*arry[Size],unsigned char Lngth)
{
    unsigned int i=0;
    int num=0;
    while (Lngth--)
    {
         printf("\n please enter the %d num of array :\t",Size-Lngth);
         scanf("%d",&num);
         i++;
         if(num != -1)
            *arry++ = num;
         else
            return(i);

    }
    return (i);

}

void AddNum(unsigned int*arry[Size],unsigned char lnght,unsigned int cnt)
{   unsigned int Num;
    printf("\n\n please enter the Num : \t");
    scanf("%d",&Num);
    *(arry+cnt)=Num;
}
void PrintArray(unsigned int*arry[Size],unsigned char Lngth,unsigned int cnt)
{
    printf("\n\n{ ");
    while (cnt--)
        printf("%d  ",*arry++);
    printf("}");
}
