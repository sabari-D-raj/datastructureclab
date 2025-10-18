#include<stdio.h>
int main(){
    int a[10],min,loc,n;
    printf("enter the size of the array");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the elements: ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        min=a[i];
        loc=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                loc=j;
            }
        }
    a[loc]=a[i];
    a[i]=min;
    
    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    
}