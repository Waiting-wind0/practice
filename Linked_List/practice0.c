#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

int main()//链表基本定义
{
    struct Node *p;
    p = malloc(sizeof(struct Node));
    if(p == NULL){
        printf("memory allocation failure");
        return -1;
    }

    p->data = 10;
    p->next = NULL;
    printf("%d\n",p->data);
    free(p);    
    return 0;
    

}