#include<stdio.h>
int size,q[10],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main(){
    int choice;
    printf("enter the size of queue: ");
    scanf("%d",&size);
    do{
        printf("enter your choice 1.enqueue 2,display 3.dequeue 4.exists: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();break;
            case 2: display();break;
            case 3: dequeue();break;
            case 4:break;
            default:printf("invalid statement:");
        }
    }while(choice!=4);
    return 0;
}
void enqueue(){
    int item;
    if(rear==size-1){
        printf("overflow \n");
    }
    else{
        if(front==-1){
            front=0;        
        }
        printf("enter the element you want to enqueue: ");
        scanf("%d",&item);
        rear++;
        q[rear]=item;
    }
}
void dequeue(){
    int item;
    if(front==-1){
        printf("underflow \n");
    }
    else{
        if(front==rear){
            item=q[front];
            front=-1;
            rear=-1;
            printf("the dequeued element is %d\n",item);
        }
        else{
            item=q[front];
            front++;
            printf("the dequeued element is %d\n",item);
        }
    }
}
void display(){
    if(front==-1){
        printf("queue is empty\n");
    }
    else{
        printf("the elements in the queue are:\n");
        for(int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}