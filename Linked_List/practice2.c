#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main() //尾插法建立链表
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *newNode = NULL;

    int x;
    printf("请输入整数，输入-1结束：\n");
    while(scanf("%d",&x) && x != -1){
        newNode = malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("内存分配失败\n");
            return -1;
        }
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("链表内容为：\n");
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }

    struct Node *freeNode = head;
    while(head != NULL){
        freeNode = head;
        head = head->next;
        free(freeNode);1 

    }

    return 0;     
}
