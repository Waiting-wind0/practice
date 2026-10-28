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
    for(int i =0; i < 10; i++)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("内存分配失败\n");
            return -1;
        }
        newNode->data = (i+1) * 10;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
        } 
        else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head; 
        head->prev = tail;
        }

    }
    printf("正向遍历链表:\n");
    struct Node *temp = head;
    do{
        printf("%d\n",temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("逆向遍历链表:\n");
    temp = tail;
    do{
        printf("%d\n",temp->data);
        temp = temp->prev;
    }while(temp != tail);
    
    head->prev = NULL;
    while(tail != NULL)
    {
        temp = tail;
        tail = tail->prev;
        free(temp);
    }
    return 0;
}
