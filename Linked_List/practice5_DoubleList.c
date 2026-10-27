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
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for(int i = 0; i < 10; i++)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = rand()%100 + 1;
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
    struct Node *ht = head;
    printf("正向遍历链表:\n");
    while(ht != NULL){
        printf("%d\n",ht->data);
        ht = ht->next;
    }
    struct Node *th = tail;
    printf("反向遍历链表:\n");
    while(th != NULL){
        printf("%d\n",th->data);
        th = th->prev;
    }
    free(th);
    free(ht);
    while(head != NULL){
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
