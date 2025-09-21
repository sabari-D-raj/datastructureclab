#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head,*ptr,*ptr1;
void create();
void push();
void pop();
void display();
int main(){
    create();
    int choice;
    do{
        printf("enter your choice \n 1:push ,\n 2:pop \n 3:display \n 4: exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:break;
        }
    }while(choice!=4);
}
void create(){
    head=(struct node*)malloc(sizeof(struct node));
    head->link=NULL;
}
void push(){
    ptr=(struct node*)malloc(sizeof(struct node ));
    if(ptr==NULL){
        printf("invalid");
    }
    else if(head->link==NULL){
        printf("enter the data:");
        scanf("%d",&ptr->data);
        ptr->link=head->link;
        head->link=ptr;
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
void pop(){
    ptr=head->link;
    if(ptr->link == NULL){
        head->link = NULL;
        free(ptr);
        return;
    }
    while(ptr->link!=NULL){
        ptr1=ptr;
        ptr=ptr->link;
    }
    ptr1->link=NULL;
    free(ptr);
}
void display(){
    ptr=head->link;
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->link;
    }
}