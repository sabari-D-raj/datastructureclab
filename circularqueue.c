#include<stdio.h>
int size,cq[10],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main(){
    int choice;
    printf("enter the size of the queue: ");
    scanf("%d",&size);
    do{
        printf("enter your choice 1.enqueue 2.dequeue 3.display 4.exists: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:break;
            default:printf("invalid");
        }
    }while(choice!=4);
    return 0;
}
void enqueue(){
    int item;
    if((rear+1)%size==front){
        printf("overflow \n");
    }
    else if(front==-1 || rear==-1){
        front=0;
        rear=0;
        printf("enter your element: ");
        scanf("%d",&item);
        cq[rear]=item;
        printf("you added element %d ",item);
    }
    else{
        printf("enter the iteam you want to add: ");
        scanf("%d",&item);
        rear=(rear+1)%size;
        cq[rear]=item;
    }
}
void dequeue(){
    int iteem;
    if(front==-1 && rear==-1){
        printf("underflow \n");
    }
    else if(front ==rear){
        iteem=cq[front];
        front=-1;
        rear=-1;
    }
    else{
        cq[front]=0;
        front=(front+1)%size;
    }
}
void display(){
    for(int i=0;i<size;i++){
        printf("%d \n",cq[i] );
    }
}