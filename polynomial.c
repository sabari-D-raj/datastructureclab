#include<stdio.h>
struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];
int readpoly(struct poly[10]);
void display(struct poly[10],int terms);
int t1,t2,t3;
int add(struct poly p1[10],struct poly p2[10],int ,int ,struct poly p3[10]);
int main(){
    t1=readpoly(p1);
    display(p1,t1);
    t2=readpoly(p2);
    t3=add(p1,p2,t1,t2,p3);
    printf("result");
    display(p3,t3);
    return 0;
}
int readpoly(struct poly p[10]){
    int t1;
    printf("enter the terms of the  polynomial");
    scanf("%d",&t1);
    printf("enter coeffeicient and exponetial");
    for(int i=0;i<t1;i++){
        printf("enter the coeffcient(%d): ",i+1);
        scanf("%d",&p[i].coeff);
        printf("enter the exponetial(%d): ",i+1);
        scanf("%d",&p[i].expo);
    }
    return t1;
}
int add(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]){
    int i=0,j=0,k=0;
    while(i<t1&&j<t2){
        if(p1[i].expo==p2[j].expo){
            p3[k].coeff=p1[i].coeff+p2[i].coeff;
            p3[k].expo=p1[i].expo;
            i++; j++;k++;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else{
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
    }
    while(i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;k++;
    }
    while(j<t2){
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        k++;j++;
    }
    return k;
}
void display(struct poly p[10],int terms){
    int k;
    for(k=0;k<terms-1;k++){
        printf("%d(X^%d)+",p[k].coeff,p[k].expo);
    }
    printf("%d(X^%d)",p[terms-1].coeff,p[terms-1].expo);


}