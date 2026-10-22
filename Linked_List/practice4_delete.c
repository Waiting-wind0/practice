#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *creatList()
{
    struct Node *head = NULL;
    struct Node *p[10];
    for(int i = 0; i < 10; i++)
    {
        p[i] = malloc(sizeof(struct Node));
        if(p[i] == NULL){
            for(int j = 0; j < i; j++){
                free(p[j]);
            }
            printf("内存分配失败\n");
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
int main(){
    struct Node *head = creatList();
    if(head ==NULL) return -1;
    int count = 0;
    printf("请输入要删除的节点位置(1-10): ");
    scanf("%d",&count);
    if(count < 1 || count > 10){
        printf("位置无效\n");
        return -1;
    }
    else{
        struct Node *temp = head;
        for(int i = 0; i < count - 2; i++){
            temp = temp->next;
        }
        if(count == 1){
            head = head->next;
            free(temp);
        }
        else{
            struct Node *delete = temp->next;
            temp->next = delete->next;
            free(delete);
        }
    }
    while(head != NULL){
        printf("%d\n",head->data);
        head = head->next;
    }
    return 0;
}
//阿他浪,有点怪怪的啊