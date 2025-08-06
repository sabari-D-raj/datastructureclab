#include<stdio.h>
int main(){
    int s[10][10],ts[10][10],rows,coloumns;
    printf("enter the no of non-zero elements");
    scanf("%d",&rows);
    for(int i= 0;i<=rows;i++){
        for(int j=0;j<3;j++){
            printf("enter the elements of rows: %d and coloumn: %d : ",i,j);
            scanf("%d",&s[i][j]);
        }
    }
    ts[0][0]=s[0][1];
    ts[0][1]=s[0][0];
    ts[0][2]=s[0][2];
    for(int i=0;i<=rows;i++){
        for(int j=0;j<3;j++){
            ts[i][0]=s[i][1];
            ts[i][1]=s[i][0];
            ts[i][2]=s[i][2];
    
        }
    }
    printf("---transposematrix---\n");
    for(int i=0;i<=rows;i++){
        for(int j=0;j<3;j++){
            printf("%d \t",ts[i][j]);
        }
        printf("\n");
    }
    return 0;
}