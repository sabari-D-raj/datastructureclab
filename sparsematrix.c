#include<stdio.h>
int main(){
int a[10][10],b[10][10],row,coloumn;
    printf("enter the number of rows and coloumns of the matrix");
    scanf("%d%d",&row,&coloumn);
    printf("---enter elements---");
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            printf("enter the elements: %d rows",i);
            scanf("%d",&a[i][j]);
        }
    }
    b[0][0]=row;
    b[0][1]=coloumn;
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                 k++;
            }
        }
    }
    b[0][2]=k-1;
    printf("---sparse matrix----\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}