#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *creatList()//创建链表然后返回头节点
{
    struct Node *p[10];
    
    for(int i = 0; i < 10;i++)
    {
        p[i] = malloc(sizeof(struct Node));
        if(p[i] == NULL){
            for(int j = 0; j < i; j ++){
                free(p[j]);
            }
            return NULL;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        p[i]->data = (i+1) * 10;
        p[i]->next = (i < 9) ? p[i+1] : NULL;
    }
    return p[0];
}
int main()//链表插入
{
    struct Node *head = creatList();
    struct Node *p;
    p = head; 
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = 15;
    newNode->next = p->next->next;
    p->next = newNode;
    while(p->next != NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
    return 0;

}