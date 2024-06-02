#include<stdio.h>
#include <stdlib.h>
void findMax(int **data, int rows, int cols, int *maxValue, int *maxRow, int *maxCol);  
int main(){
    int rows,cols;
    scanf("%d",&rows);
    scanf("%d",&cols);
    int **data = (int ** ) calloc(rows,sizeof(int *));
    for(int i=0;i<rows;i++){
            data[i]= (int *) calloc(cols,sizeof(int));
        for(int j=0;j<cols;j++){
            scanf("%d",data[i]+j);
        }
    }
    int maxValue,maxRow,maxCol;
    findMax(data,rows,cols,&maxValue,&maxRow,&maxCol);
    for(int i=0;i<rows;i++){
        free(data[i]);
    }
    free(data);
    return 0;
}

void findMax(int **data, int rows, int cols, int *maxValue, int *maxRow, int *maxCol){
    *maxValue=data[0][0];
    *maxCol = 0;
    *maxRow = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (*maxValue<data[i][j]){
                *maxValue=data[i][j];
                *maxRow = i;
                *maxCol = j;
            }
        }
    }
    printf("%d %d %d",*maxValue,*maxCol+1,*maxRow+1);
}