#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head,*ptr,*ptr1,*ptr2;
void create_list();
void insert_front();
void insert_btw();
void insert_end();
void delete_front();
void delete_end();
void delete_btw();
void display();
int main(){
    create_list();
    int choice,choice1;
    do{
    printf("enter your choice \n 1:insert \n 2:delete \n 3:display \n 4 exit: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter your choice \n 1: insert at front \n 2: insert between \n 3:insert at end : ");
                scanf("%d",&choice1);
                switch(choice1){
                    case 1: insert_front();break;
                    case 2: insert_btw();break;
                    case 3: insert_end();break;
                }
                break;
        case 2: printf("enter your choice \n 1: delete at front \n 2: delete between \n 3:delete at end : ");
                scanf("%d",&choice1);
                switch(choice1){
                    case 1:delete_front();break;
                    case 2: delete_btw();break;
                    case 3: delete_end();break;
                }
                break;
        case 3:display();break;
        case 4: break;
        default: printf("invalid");
    }
    }while(choice!=4);
    return 0;
}
void create_list(){
    head=(struct node*)malloc(sizeof(struct node));
    head ->link =NULL;
}
void insert_front(){
    ptr =(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("memory not available");
    }
    else{
        ptr ->link=head->link;
        printf("enter the data:");
        scanf("%d",&ptr->data);
        head->link=ptr;
    }
}
void insert_btw(){
    int key;
    printf("enter the key:");
    scanf("%d",&key);
    ptr2=(struct node*)malloc(sizeof(struct node));
    if(ptr2==NULL){
        printf("memory not available");
    }
    else{
        ptr1=head;
        while(ptr1!=NULL &&  ptr1->data!=key ){
            ptr=ptr1;
            ptr1=ptr1->link;
        }
        if(ptr1==NULL){
            printf("not found");
        }
        else{
            
            printf("enter the data");
            scanf("%d",&ptr2->data);
            ptr2->link=ptr->link;
            ptr->link=ptr2;
        }
    }
}
void insert_end(){
    ptr=(struct node*)malloc(sizeof(struct node));
     if(ptr==NULL){
        printf("memory not available");
    }
    else{
        ptr1=head;
        while(ptr1->link!=NULL){
            ptr1=ptr1->link;
        }
        ptr1->link=ptr;
        printf("enter the data");
        scanf("%d",&ptr->data);
        ptr->link=NULL;
    }
}
void delete_front(){
    if(head->link==NULL){
        printf("not available");
    }
    else{
        ptr=head->link;
        ptr1=ptr->link;
        head->link=ptr1;
        free(ptr);
    }
}
void delete_end(){
    ptr=head;
    if(ptr==NULL){
        printf("nothing");
    }
    else{
        while(ptr->link!=NULL){
            ptr2=ptr;
            ptr=ptr->link;
        }
        ptr2->link=NULL;
        free(ptr);
    }
}
void delete_btw(){
    int k;
    printf("enter the data you want to delete:");
    scanf("%d",&k);
    ptr1=head;
    ptr=ptr1->link;
    while(ptr != NULL){
        if(ptr->data == k){
            ptr1->link = ptr->link;
            free(ptr);
            printf("Node with data %d deleted\n", k);
            return; 
        } else {
            ptr1 = ptr;
            ptr = ptr->link;
        }
    }
     if(ptr==NULL){
        printf("nothing");
    }
}
   

void display(){
    ptr=head->link;
    while(ptr!=NULL){
        printf("[%d:%d]--> ", ptr->data, ptr->link);
        ptr=ptr->link;
    }
    printf("NULL\n");
}