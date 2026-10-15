#include <stdio.h>
#include <stdlib.h>
struct Node{    
    int data;
    struct Node *next;
};

int main()//链表直接建立以及输出
{
    struct Node *head = NULL;
    struct Node *p1;
    struct Node *p2;
    struct Node *p3;

    p1 = malloc(sizeof(struct Node));
    p2 = malloc(sizeof(struct Node));
    p3 = malloc(sizeof(struct Node));

    if(p1 == NULL || p2 == NULL || p3 == NULL){
        free(p1);
        free(p2);
        free(p3);
        printf("memory allocation failure");
        return -1;
    }

    p1->data = 10;
    p2->data = 20;
    p3->data = 30;

    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;

    head = p1;
    printf("%d\n",head->data);
    printf("%d\n",head->next->data);
    printf("%d\n",head->next->next->data);//这里可以用循环，head = head->next;

    free(p1);   
    free(p2);
    free(p3);

    return 0;



}