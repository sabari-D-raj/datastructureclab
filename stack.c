#include<stdio.h>
void push();
void pop();
void display();
int top=-1;
int size, stack[10],item;
int main(){
    int choice;
    printf("enter the number of stack: ");
    scanf("%d",&size);
    do{
        printf("enter your choice 1:push, 2:pop ,3:display 4:exists : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:break;
            default: printf("invalid statement");
        }
    }while(choice!=4);
    return 0;
}
void push(){
    if(top==size-1){
        printf("overflow \n");
    }
    else{
        printf("enter the element: ");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
void pop(){
    if(top==-1){
        printf("underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("element poped");
    }
}
void display(){
    
    printf("Current stack:\n");
    for (int i = size; i >= 0; i--) {
        printf("-----\n");
        printf("%d | %d |\n",i, stack[i]);
    }
    printf("-----\n");
}