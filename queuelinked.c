#include<stdio.h>
#include<stdlib.h>
void create();
void enqueue();
void dequeue();
void display();
struct node{
    int data;
    struct node *link;
}*head,*ptr,*ptr1;
int main(){
    int choice;
    create();
    do{
        printf("enter your choice \n 1:enqueue \n 2:dequeue \n 3: display\n 4:exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:break;
            default:printf("invalid");
        }
    }while(choice!=4);
}
void create(){
    head=(struct node*)malloc(sizeof(struct node));
    head->link=NULL;
}
void enqueue(){
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("invalid");
    }
    else if(head->link==NULL){
        printf("enter the data:");
        scanf("%d",&ptr->data);
        head->link=ptr;
        ptr->link=NULL;
    }
    else{
        ptr1=head->link;
        while(ptr1->link!=NULL){
            ptr1=ptr1->link;
        }
        printf("enter the data:");
        scanf("%d",&ptr->data);
        ptr1->link=ptr;
        ptr->link=NULL;
    }
    
}
void dequeue(){
    if(head->link==NULL){
        printf("underflow");
    }
    else{
        ptr=head->link;
        ptr1=ptr->link;
        head->link=ptr1;
        free(ptr);
    }
}
void display(){
    ptr=head->link;
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->link;
    }
    printf("Null \n");
}