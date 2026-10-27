#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int data;
    struct Node *next;
};

int main()
{
    srand((unsigned int)time(NULL));
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for(int i = 0; i < 10; i++)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("内存分配失败\n");
            return -1;
        }
        newNode->data = rand() % 100;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    struct Node *temp = head;
    printf("遍历循环链表:\n");
    do{
        printf("%d\n",temp->data);
        temp = temp->next;
    }while(temp !=head);
    tail->next = NULL;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}