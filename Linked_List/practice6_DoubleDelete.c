#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
int main()
{
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
    printf("请输入要删除的节点位置(1-10): ");
    scanf("%d",&count);
    if(count < 1 || count > 10){
        printf("位置无效\n");
        return -1;
    }
    else{
        for(int i = 0;i < count -1;i++)
        {
            temp = temp->next;
        }
    }
    if(temp == head){
        head = head->next;
        head->prev = NULL;
        }
    else if(temp == tail){
        tail = tail->prev;
        tail->next = NULL;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    struct Node *p = head;
    while(p != NULL){
        printf("%d\n",p->data);
        p = p->next;
    }           
    while(head != NULL){
        struct Node *tem = head;
        head = head->next;
        free(tem);
    }
    return 0;
}