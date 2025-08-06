#include<stdio.h>
int size,elements,s[20];
void push();
void pop();
void display();
struct stack{
   int max;
   int min;
   int top; 
}stackval[10];
int stackvalindex=-1;
int main(){
    int choice;
    printf("how many stacks do want: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("enter the no of elements of stack:%d" ,i);
        scanf("%d",&elements);
        if(stackvalindex=-1){
            stackvalindex +=1;
            stackval[stackvalindex].top=-1;
            stackval[stackvalindex].max=elements-1;
            stackval[stackvalindex].min=0;
        }
        else{
            stackvalindex +=1;
            stackval[stackvalindex].top=stackval[stackvalindex-1].max+1;
            stackval[stackvalindex].max=stackval[stackvalindex].top+elements;
            stackval[stackvalindex].min=stackval[stackvalindex].top;
        }
    }

    do{
        printf("enter your choice 1.push 2.pop 3.display 4.exist: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();break;
            case 2: pop();break;
            case 3: display();break;
            case 4:break;
            default:printf("invalid statement:");
        }
    }while(choice!=4);
    return 0;
}
void push(){
    int st,item;
    printf("enter which stack do you want to push elements: ");
    scanf("%d",&st);
    if(stackval[st].top+1>stackval[st].max){
        printf("overflow \n");
    }
    else{
        printf("enter the elements you want to push");
        scanf("%d",&item);
        s[stackval[st].top]=item;
        stackval[st].top++;
    }
}
void pop(){
    int st,item;
    printf("enter the the stack you want to pop: ");
    scanf("%d",&st);
    if(stackval[st].top<stackval[st].min){
        printf("underflow");
    }
    else{
        item = s[stackval[st].top];
        stackval[st].top--;
        printf("the popped element is %d",item);    
    }
}
void display(){
    int st;
    printf("enter the stack you want to display: ");
    scanf("%d",&st);
    printf("the elements in the stack are:\n ");
        for(int i=stackval[st].min;i<=stackval[st].top;i++){
            printf("%d ",s[i]);
        }
        printf("\n");
}


