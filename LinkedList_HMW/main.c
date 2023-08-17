#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _Node{
    uint16_t num;
    struct _Node* next;
}Node;

typedef struct {
    Node* root;
    uint32_t len;
}LinkedList;

void LinkedList_init(LinkedList* list);
void LinkedList_show(LinkedList* list);
void LinkedList_add(LinkedList* list, uint16_t num);
void LinkedList_del(LinkedList* list, uint32_t index);
void LinkedList_delNum(LinkedList* list, uint16_t num);
void LinkedList_delNumFirst(LinkedList* list, uint16_t num);
int32_t LinkedList_indexFirst(LinkedList* list, uint16_t num);
void LinkedList_insert(LinkedList* list, uint16_t num, uint32_t index);
void LinkedList_update(LinkedList* list, uint16_t num, uint32_t index);


int main()
{
    LinkedList list;
    LinkedList_init(&list);
    LinkedList_add(&list, 1);
    LinkedList_add(&list, 2);
    LinkedList_add(&list, 3);
    LinkedList_add(&list, 4);
    LinkedList_show(&list);
    //LinkedList_del(&list, 10);
    //LinkedList_show(&list);]
    //printf("\n\nthe first index of num %d is %d",2,LinkedList_indexFirst(&list,2));
    //LinkedList_delNum(&list,3);
    printf("\n");
    //LinkedList_update(&list,2,4);
    LinkedList_insert(&list,8,0);
    LinkedList_show(&list);
    return 0;
}

void LinkedList_init(LinkedList* list){
    list->len = 0;
    list->root = NULL;
}

void LinkedList_add(LinkedList* list, uint16_t num){
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
    node->next = NULL;

    if(list->root == NULL){
        list->root = node;
    } else{
        // step1: find last node
        Node* probe = list->root;
        uint32_t len = list->len;
        while(--len){
            probe = probe->next;
        }
        // step2: assign new address to next param
        probe->next = node;
    }
    list->len++;
}

void LinkedList_show(LinkedList* list){
    Node* probe = list->root;
    uint32_t len = list->len;
    while(len--){
        printf("value: %d, address: %d\n", probe->num, probe);
        probe = probe->next;
    }
}

void LinkedList_del(LinkedList* list, uint32_t index){
    if(index > list->len){
        return;
    }

    Node* probe = list->root;

    if(index != 0){
        index -= 1;
        while(index--){
        probe = probe->next;
        }
        Node* delItem = probe->next;
        probe->next = probe->next->next;
        free(delItem);
    } else{
        list->root = list->root->next;
        free(probe);
    }
    list->len--;
}

int32_t LinkedList_indexFirst(LinkedList* list, uint16_t num)
{
    Node* prob=list->root;
    uint32_t len=list->len;
    while(len--)
    {
        if(prob->num==num)
            return((list->len)-len);
        prob=prob->next;
    }
}

void LinkedList_delNumFirst(LinkedList* list, uint16_t num)
{
    Node* prob = list->root;
    uint32_t len = list->len;
    uint32_t counter = 0;

    while(len--)
    {
        Node* preprob = list->root;
        counter = (list->len) - len - 2;
        if(num == prob->num)
        {
            if((len+1)!= list->len)
            {
                while(counter--)
                    preprob = preprob->next;

                preprob->next = prob->next;
                free(prob);

            }else{

                list->root = list->root->next;
                free(preprob);
            }
            list->len--;
        }
        prob = prob->next;
    }
}

void LinkedList_delNum(LinkedList* list, uint16_t num)
{
    Node* prob = list->root;
    uint32_t len = list->len;
    uint32_t counter = 0;

    while(len--)
    {
        Node* preprob = list->root;
        Node *temp=prob;
        counter = (list->len) - len - 2;
        if(num == prob->num)
        {
            if((len+1)!= list->len)
            {
                while(counter--)
                    preprob = preprob->next;
                Node* delItem = prob;
                preprob->next = prob->next;
                prob=prob->next;
                free(delItem);

            }else{

                list->root = list->root->next;
                prob = prob->next;
                free(preprob);
            }
            list->len--;


        }else{
            prob = prob->next;
        }
    }
}
void LinkedList_update(LinkedList* list, uint16_t num, uint32_t index)
{
    Node* prob = list->root;
    uint32_t len = list->len;
    if(index > len)
        return;
    else
    {
        while(index--)
            prob = prob->next;
        prob->num = num;
    }
}

void LinkedList_insert(LinkedList* list, uint16_t num, uint32_t index)
{
    Node* prob = list->root;
    uint32_t len = list->len;
    index;
    if(index > len)
        return;
    else
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->num = num;
        if(index != len)
        {
            if(index == 0)
            {
                node->next = prob;
                list->root = node;
            }
            else
            {
                while(--index)
                    prob = prob->next;

                node->next = prob->next;
                prob->next = node;
            }

        }else{

            while(--index)
                prob = prob->next;
            node->next = NULL;
            prob->next = node;
            printf("%d",prob->num);
        }
        list->len++;
    }
}
