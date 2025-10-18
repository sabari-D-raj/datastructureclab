#include<stdio.h>
int n,b[50],a[50];
void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void display();
int main(){
    printf("enter the size of the array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element:");
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    display();
    return 0;
}
void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high){
   int  i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        a[i]=b[i];
    }
}
void display(){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}