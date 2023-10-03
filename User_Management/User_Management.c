#include "User_Management.h"


void User_init(User_List * List)
{
    List->root = NULL;
    List->User_Len= 0;
}


void User_Add_ID_End(User_List * List , uint8_t user_Name [Name_ln] , uint8_t user_Age )
{
    uint8_t ListLen = List->User_Len;
    User * New_User = (User*)malloc(sizeof(User));
    New_User->Age = user_Age;
    strcpy(New_User->Name , user_Name);
    New_User->next = NULL;
    if(ListLen == 0)
    {
        New_User->ID = 1;
        New_User->pre = NULL;
        List->root = New_User;
    }
    else
    {
        User *prob = List->root;
        User *preprob = List->root;
        while(--ListLen)
        {
            prob = prob->next;
        }
        prob->next = New_User;
        preprob = prob;
        prob = prob->next;
        prob->pre = preprob;
        prob->ID = List->User_Len + 1;
    }
    List->User_Len++;
}

void User_show_All(User_List * List)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    while(ListLen--)
    {
        printf("\nUser %2d : name : %s  age : %3d ID : %2d\n",(List->User_Len - ListLen),prob->Name,prob->Age,prob->ID);
        prob = prob->next;
    }
    /*ListLen = List->User_Len;
    prob = List->root;
    while(--ListLen)
        prob = prob->next;
    ListLen = List->User_Len;
    while(ListLen--)
    {
        printf("\nUser %2d : name : %s  age : %3d ID : %2d\n",ListLen,prob->Name,prob->Age,prob->ID);
        prob = prob->pre;
    }
    */
}

int8_t User_Remove_ID_First(User_List * List , uint8_t ID)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    User *preprob = NULL;
    User *nextprob = NULL;

    while(ListLen--)
    {
        if(prob->ID != ID)
        {
            prob = prob->next;
        }
        else
        {
            if(ListLen == List->User_Len - 1)
            {
                if(List->User_Len != 1)
                {
                    nextprob = prob->next;
                    nextprob->pre = NULL;
                    List->root = nextprob;
                }
                else
                {
                    List->root = NULL;
                }
            }
            else if(!ListLen)
            {
                preprob = prob->pre;
                preprob->next = NULL;
            }
            else
            {
                preprob = prob->pre;
                nextprob = prob->next;
                preprob->next = nextprob;
                nextprob->pre = preprob;
            }
            free(prob);
            List->User_Len--;
            return (ID);

        }

    }
    return(-1);
}

int8_t User_Remove_Age_First(User_List * List , uint8_t Age)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    User *preprob = NULL;
    User *nextprob = NULL;
    uint8_t ID = 0;

    while(ListLen--)
    {
        if(prob->Age != Age)
        {
            prob = prob->next;
        }
        else
        {
            ID = prob->ID;
            if(ListLen == List->User_Len - 1)
            {
                if(List->User_Len != 1)
                {
                    nextprob = prob->next;
                    nextprob->pre = NULL;
                    List->root = nextprob;
                }
                else
                {
                    List->root = NULL;
                }
            }
            else if(!ListLen)
            {
                preprob = prob->pre;
                preprob->next = NULL;
            }
            else
            {
                preprob = prob->pre;
                nextprob = prob->next;
                preprob->next = nextprob;
                nextprob->pre = preprob;
            }
            free(prob);
            List->User_Len--;
            return (ID);

        }

    }
    return(-1);

}

int8_t User_Remove_Name_First(User_List * List , uint8_t Name[Name_ln])
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    User *preprob = NULL;
    User *nextprob = NULL;
    uint8_t ID = 0;

    while(ListLen--)
    {
        if(strcmp(prob->Name ,Name) != 0)
        {
            prob = prob->next;
        }
        else
        {
            ID = prob->ID;
            if(ListLen == List->User_Len - 1)
            {
                if(List->User_Len != 1)
                {
                    nextprob = prob->next;
                    nextprob->pre = NULL;
                    List->root = nextprob;
                }
                else
                {
                    List->root = NULL;
                }
            }
            else if(!ListLen)
            {
                preprob = prob->pre;
                preprob->next = NULL;
            }
            else
            {
                preprob = prob->pre;
                nextprob = prob->next;
                preprob->next = nextprob;
                nextprob->pre = preprob;
            }
            free(prob);
            List->User_Len--;
            return (ID);
        }

    }
    return(-1);

}

int8_t User_Remove_Age_All(User_List * List , uint8_t Age)
{
    uint8_t counter = 0;
    int8_t res = User_Remove_Age_First(List , Age);

    while(res != -1)
    {
        counter++;
        res = User_Remove_Age_First(List , Age);
    }
    return(counter);

}

int8_t User_Remove_Name_All(User_List * List , uint8_t Name[Name_ln])
{
    uint8_t counter = 0;
    int8_t res = User_Remove_Name_First(List , Name);

    while(res != -1)
    {
        counter++;
        res = User_Remove_Name_First(List , Name);
    }
    return(counter);

}

int8_t User_Update(User_List * List , uint8_t ID , uint8_t Age ,uint8_t Name[Name_ln])
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    while(ListLen--)
    {
        if(prob->ID != ID)
        {
            if(List->User_Len > 1)
                prob = prob->next;
        }
        else
        {
            prob->Age = Age;
            strcpy(prob->Name , Name);
            return (ID);
        }
    }
    return(-1);
}

int8_t User_Find_ID_First(User_List * List , uint8_t ID)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;

    while(ListLen--)
    {
        if(prob->ID != ID)
        {
            if(List->User_Len > 1)
                prob = prob->next;
        }
        else
        {
            return (ID);
        }
    }
    return(-1);
}

int8_t User_Find_Age_First(User_List * List , uint8_t Age)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;

    while(ListLen--)
    {
        if(prob->Age != Age)
        {
            if(List->User_Len > 1)
                prob = prob->next;
        }
        else
        {
            return (prob->ID);
        }
    }
    return(-1);
}

int8_t User_Find_Name_First(User_List * List , uint8_t Name[Name_ln])
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;

    while(ListLen--)
    {
        if(strcmp(prob->Name , Name) != 0)
        {
            if(List->User_Len > 1)
                prob = prob->next;
        }
        else
        {
            return (prob->ID);
        }
    }
    return(-1);

}

int8_t User_Find_Age_All(User_List * List , uint8_t Age)
{
    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    uint8_t counter = 0;

    while(ListLen--)
    {
        if(prob->Age == Age)
            counter++;
        prob = prob->next;
    }
    return(counter? counter:-1);
}

int8_t User_Find_Name_All(User_List * List , uint8_t Name[Name_ln])
{

    uint8_t ListLen = List->User_Len;
    User *prob = List->root;
    uint8_t counter = 0;

    while(ListLen--)
    {
        if(strcmp(prob->Name , Name) == 0)
            counter++;
        prob = prob->next;
    }
    return(counter? counter:-1);

}

void User_Switch_ID(User_List * List , uint8_t Frst_ID , uint8_t Sec_ID)
{
    User *prob = List->root;
    User *Frstprob = NULL;
    User *Secprob = NULL;
    uint8_t temp_ID = 0;
    uint8_t temp_Age = 0;
    uint8_t temp_Name[Name_ln];
    uint8_t ListLen = List->User_Len;

    while(ListLen--)
    {
        if(prob->ID == Frst_ID)
            Frstprob = prob;

        else if(prob->ID == Sec_ID)
            Secprob = prob;

        prob = prob->next;
    }

    temp_ID = Frstprob->ID;
    temp_Age = Frstprob->Age;
    strcpy(temp_Name , Frstprob->Name);

    Frstprob->ID = Secprob->ID;
    Frstprob->Age = Secprob->Age;
    strcpy(Frstprob->Name , Secprob->Name);

    Secprob->ID = temp_ID;
    Secprob->Age = temp_Age;
    strcpy(Secprob->Name , temp_Name);
}
void User_Sort_ID(User_List * List,uint8_t order)
{
    User *prob = List->root;
    User *nextprob = NULL;
    uint8_t ListLen = List->User_Len;
    uint8_t Sort_Len = 0;
    while(--ListLen)
    {
        prob = List->root;
        Sort_Len = ListLen;
        while(Sort_Len--)
        {
            nextprob = prob->next;
            if(prob->ID < nextprob->ID && order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            else if(prob->ID > nextprob->ID && !order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            prob = prob->next;
        }
    }

}

void User_Sort_Name(User_List * List , uint8_t order)
{
    User *prob = List->root;
    User *nextprob = NULL;
    uint8_t ListLen = List->User_Len;
    uint8_t Sort_Len = 0;
    while(--ListLen)
    {
        prob = List->root;
        Sort_Len = ListLen;
        while(Sort_Len--)
        {
            nextprob = prob->next;
            if(strcmp(prob->Name , nextprob->Name) < 0 && order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            else if(strcmp(prob->Name , nextprob->Name) > 0 && !order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            prob = prob->next;
        }
    }
}

void User_Sort_Age(User_List * List , uint8_t order)
{
    User *prob = List->root;
    User *nextprob = NULL;
    uint8_t ListLen = List->User_Len;
    uint8_t Sort_Len = 0;
    while(--ListLen)
    {
        prob = List->root;
        Sort_Len = ListLen;
        while(Sort_Len--)
        {
            nextprob = prob->next;
            if(prob->Age < nextprob->Age && order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            else if(prob->Age > nextprob->Age && !order)
                User_Switch_ID(List , prob->ID , nextprob->ID);
            prob = prob->next;
        }
    }
}
