//queueproblem.c -- Lab 02 -- Saad, Rizvi
#include <stdio.h>
#include <stdlib.h>

#define MAX 400

struct node{
    int data;
    struct node *next;
};

struct queue {
    struct node *head, *tail;
};

struct queue* initialize(){                                                     //Initializes a given queue
    struct queue *temp = (struct queue*)malloc(sizeof(struct node));
    temp -> head = temp -> tail = NULL;
    return temp;
}

void EnQueue(struct queue *myqueue, int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;

    if(myqueue->tail == NULL){
        myqueue -> head = myqueue -> tail = temp;
        return;
    }

    myqueue -> tail -> next = temp;
    myqueue -> tail = temp;
}

void print(struct queue *queue){
    struct node *temp = queue -> head;
    while(temp!=NULL){
        printf("%d  ", temp->data);
        temp = temp -> next;
    }
}

int main(){
    struct queue *q1, *q2, *q3, *q4;
    q1 = initialize();
    q2 = initialize();
    q3 = initialize();
    q4 = initialize();
    
    int x[MAX];
    int i = 0;
    int j = 1;

    printf("Enter numbers with a final negative number to signify the end: \n");

    while(j > 0){
        scanf("%d", &x[i]);
        if (x[i] < 0) j = 0;
        i++;
    }

    for(int p = 0; p<i && x[i] >= 0; p++){
        int a = x[p] % 4;
        if(a == 0)
        EnQueue(q1, x[p]);
        else if(a == 1)
        EnQueue(q2, x[p]);
        else if(a == 2)
        EnQueue(q3, x[p]);
        else if(a == 3)
        EnQueue(q4, x[p]);
        else
        printf("ERROR");
    } 

    printf("List 1: ");
    print(q1);
    printf("\n");
    printf("List 2: ");
    print(q2);
    printf("\n");
    printf("List 3: ");
    print(q3);
    printf("\n");
    printf("List 4: ");
    print(q4);

}