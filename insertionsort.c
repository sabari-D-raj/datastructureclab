#include<stdio.h>
int a[20],n;
int main(){
    printf("enter the size of the array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element %d",i+1);
        scanf("%d",&a[i]);
    }
    int key;
    for(int i=0;i<n-1;i++){
        key=a[i+1];
        if(a[i]>key){
            int j=i;
            while(a[j]>key && j!=-1){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
    }
    for(int k=0;k<n;k++){
        printf("%d",a[k]);
    }
}