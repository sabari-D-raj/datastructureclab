#include<stdio.h>
#include<stdlib.h>
struct node{
    int roll_no;
    char name[10];
    float mark;
    struct node *link;
}*ptr,*head,*ptr1,*ptr2;
void insertion();
void insert_btw();
void insert_end();
void delete();
void delete_end();
void delete_btw();
void display();
void creation();
int main(){
    int choice ,choice1;
    creation();
    do{
        printf("enter your choice 1:insert 2:delete 3:display 4:exist");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter your choice 1:insert front 2:insert btw 3:insert end ");
                    scanf("%d",&choice1);
                    switch(choice1){
                        case 1:insertion();break;
                        case 2: insert_btw();break;
                        case 3:insert_end();break;
                    }
                break;
            case 2:printf("enter your choice 1:delete 2:delete btw 3:delete end");
                    scanf("%d",&choice1);
                    switch(choice1){
                        case 1:delete();break;
                        case 2:delete_btw();break;
                        case 3:delete_end();break;
                    }
                break;
            case 3:display();break;
            case 4:break;
            default:printf("invalid \n");
        }
    }while(choice!=4);
    return 0;
}
void creation(){
    head=(struct node*)malloc(sizeof(struct node));
    head->link=NULL;
}
void insertion(){
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("invalid");
    }
    else{
    printf("enter the roll no:");
    scanf("%d",&ptr->roll_no);
    printf("enter the name:");
    scanf("%s",ptr->name);
    printf("enter the mark:");
    scanf("%f",&ptr->mark);
    ptr->link=head->link;
    head->link=ptr;
    }
}
void insert_btw(){
    int item;
    ptr2=(struct node*)malloc(sizeof(struct node));
    if(ptr2==NULL){
        printf("invalid");
    }
    else{
        printf("enter the roll no where you want to add");
        scanf("%d",&item);
       ptr=head->link;
       while(ptr!=NULL &&ptr->roll_no!=item){
            ptr1=ptr;
            ptr=ptr->link;
       }
       printf("enter the rollno:");
       scanf("%d",&ptr2->roll_no); 
       printf("enter the name:");
       scanf("%s",ptr2->name);
       printf("enter the mark");
       scanf("%f",&ptr2->mark);
       ptr1->link=ptr2;
       ptr2->link=ptr;
    }
}
void insert_end(){
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->link!=NULL){
       ptr=ptr->link; 
    }
    ptr->link=ptr1;
    printf("enter the rollno:");
    scanf("%d",&ptr1->roll_no);
    printf("enter the name");
    scanf("%s",ptr1->name);
    printf("enter the mark");
    scanf("%f",&ptr1->mark);
    ptr1->link=NULL;
    
}
void delete(){
    if(head->link==NULL){
        printf("nothing");
    }
    else{
    ptr=head->link;
    ptr1=ptr->link;
    head->link=ptr1;
    free(ptr);
    }
}
void delete_btw(){
    int item;
    printf("enter the roll no ");
    scanf("%d",&item);
    ptr1=head;
    ptr=ptr1->link;
    while(ptr!=NULL){
        if(ptr->roll_no==item){
            ptr1->link=ptr->link;
            free(ptr);
        }
        else{
            ptr1=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL){
            printf("nothing");
        }
    }
    
}
void delete_end(){
    ptr1=head;
    ptr=ptr->link;
    while(ptr!=NULL){
        ptr=ptr1->link;
    }
    ptr1->link=NULL;
    free(ptr);
}
void display(){
    ptr=head;
    while(ptr!=NULL){
        printf(" %d %s %f",ptr->roll_no,ptr->name,ptr->mark);
        ptr=ptr->link;
    }
}