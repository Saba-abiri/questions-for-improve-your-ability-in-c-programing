#ifndef _User_Management_H
#define _User_Management_H

#include <stdint.h>
#define Name_ln  10
#define ASE 0
#define DEC 1

// Define a structure for a user
typedef struct _User{
    uint8_t Name[Name_ln];
    uint8_t Age;
    uint8_t ID;
    struct _User *next;
    struct _User *pre;
}User;

// Define a structure for a user list
typedef struct{
    User *root;
    uint32_t User_Len;
}User_List;

void User_init(User_List * List);//initialize the user list
void User_Add_ID_End(User_List * List , uint8_t user_Name [Name_ln] , uint8_t user_Age );//add a user to the end of the list
void User_show_All(User_List * List);//show all user in the list
int8_t User_Remove_ID_First(User_List * List , uint8_t ID);//Remove a user by ID from the list
int8_t User_Remove_Age_First(User_List * List , uint8_t Age);//Remove users by Age from the list
int8_t User_Remove_Name_First(User_List * List , uint8_t Name[Name_ln]);//Remove users by Name from the list
int8_t User_Remove_Age_All(User_List * List , uint8_t Age);//Remove all users by Age from the list
int8_t User_Remove_Name_All(User_List * List , uint8_t Name[Name_ln]);//Remove all users by Name from the list
int8_t User_Update(User_List * List , uint8_t ID , uint8_t Age ,uint8_t Name[Name_ln]);//Update user information by ID
int8_t User_Find_ID_First(User_List * List , uint8_t ID);//Find user by ID
int8_t User_Find_Age_First(User_List * List , uint8_t Age);//Find first user by Age
int8_t User_Find_Name_First(User_List * List , uint8_t Name[Name_ln]);//Find first user by Name
int8_t User_Find_Age_All(User_List * List , uint8_t Age);//Find all user by Age
int8_t User_Find_Name_All(User_List * List , uint8_t Name[Name_ln]);//Find all user by Name
void User_Switch_ID(User_List * List , uint8_t Frst_ID , uint8_t Sec_ID);//Switch user positions by ID
void User_Sort_ID(User_List * List,uint8_t order);//Sort users by ID (ascending or descending order)
void User_Sort_Name(User_List * List , uint8_t order);//Sort users by Name (ascending or descending order)
void User_Sort_Age(User_List * List , uint8_t order);//Sort users by Age (ascending or descending order)

#endif // _User_Management_H


