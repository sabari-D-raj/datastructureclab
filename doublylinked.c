#include<stdio.h>
#include<stdlib.h>
void insert();
void create();
void pallindrome();
void display();
struct node{
    int data;
    struct node *Llink,*Rlink;
}*head,*ptr,*ptr1;
int main(){
    create();
    insert();
    display();
    pallindrome();
}
void create(){
    head=(struct node*)malloc(sizeof(struct node));
    head->Llink=NULL;
    head->Rlink=NULL;
}
void insert(){
    int l;
    ptr1=head;
    printf("enter the length:");
    scanf("%d",&l);
        for(int i=0;i<l;i++){
            ptr=(struct node*)malloc(sizeof(struct node));
            if(ptr==NULL){
                printf("not available \n");
            }
            printf("enter the data:");
            scanf("%d",&ptr->data);
        ptr->Llink = ptr1;
        ptr->Rlink = NULL;
        ptr1->Rlink = ptr;
        ptr1 = ptr;
        }

}
void display(){
    ptr=head->Rlink;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->Rlink;
    }
}
void pallindrome(){
    int flag=1;
    ptr=head->Rlink;
    ptr1=head->Rlink;
    while(ptr->Rlink!=NULL){
        ptr=ptr->Rlink;
    }
    while(ptr1 && ptr && ptr1 != ptr && ptr->Rlink != ptr1){
        if(ptr1->data != ptr->data){
            flag = 0;
            break;
        }
        ptr1 = ptr1->Rlink;
        ptr = ptr->Llink;
    }
    if(flag){
        printf("pallindrome");
    }
    else{
        printf("not pallindrome");
    }
}