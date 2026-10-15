#include <stdio.h>
#include <stdlib.h>
struct Node{    
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *p[10];

    for(int i = 0; i < 9; i++){
        p[i] = malloc(sizeof(struct Node));
    }

    int count = 0;
    for(int i = 0; i < 9; i++){
        if(p[i] == NULL){
            count++;
            break;
        };
    }
    if(count > 0){
        printf("memory allocation failure\n");
        
        for(int i = 0; i < 9; i++){
            free(p[i]);
        }
        return -1;
    }
    
    for(int i = 0; i < 9; i++){
        p[i]->data = 10 * (i + 1);
        p[i]->next = (i < 8) ? p[i+1] : NULL;
    }
    head = p[0];
    struct Node *temp = head;
    
    for(int i = 0; i < 9; i++){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    for(int i = 0; i < 9; i++){
        free(p[i]);
    }

    return 0;



}