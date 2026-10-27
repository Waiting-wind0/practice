#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
int main()
{
    srand((unsigned int)time(NULL));
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for(int i = 0; i < 10; i++)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = (i+1) * 10;
        if(newNode == NULL){
            printf("内存分配失败\n");
            return -1;
        }
        if(head ==NULL){
            head = newNode;
            head->prev = NULL;
            tail = newNode;
            tail->next = NULL;
        }   
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
    }
    int count = 0;
    struct Node *temp = head;
    printf("请输入要插入的节点位置(0-10): ");
    scanf("%d",&count);
    if(count < 0 || count > 10){
        printf("位置无效\n");
        return -1;
    }
    else{
        for(int i = 0;i < count -1;i++)
        {
            temp = temp->next;
        }
    }
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = rand() % 100;
    if(newNode == NULL){
        printf("内存分配失败\n");
        return -1;
    }
    if(count == 0){
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if(count == 10){
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else{
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    while(head != NULL){
        printf("%d\n",head->data);
        head = head->next;
    }  
    while(tail != NULL){
        temp = tail;
        tail = tail->prev;
        free(temp);
    }
    return 0;
}