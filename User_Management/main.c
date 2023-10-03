#include <stdio.h>
#include <stdlib.h>
#include "User_Management.h"


int main()
{
    static User_List list;
    User_init(&list);
    User_Add_ID_End(&list ,"Bina",29);
    User_Add_ID_End(&list ,"saba",26);
    User_Add_ID_End(&list ,"Ali ",27);
    User_show_All(&list);

    //printf("\nthe ID = %d removed",User_Remove_ID_First(&list ,5));
    //User_show_All(&list);

    //printf("\nthe ID = %d removed",User_Remove_Name_All(&list ,"Ali "));
    //User_show_All(&list);

    //printf("\nthe ID = %d removed",User_Remove_Age_First(&list ,25));

    //printf("\nthe ID = %d removed",User_Remove_Age_First(&list ,26));
    //User_show_All(&list);

    //printf("\nthe ID = %d have changed\n",User_Update(&list , 2 , 30 ,"akol"));
    //User_show_All(&list);

    //User_Switch_ID(&list , 2 , 3);
    //printf("\nthe num = %d \n",User_Find_Name_All(&list ,"sina"));
    User_show_All(&list);
    //User_Sort_ID(&list,DEC);
    //User_Sort_Name(&list,ASE);
    User_Sort_Age(&list ,ASE);
    User_show_All(&list);

}
