#include "hello.h"

void printDpArr(int** dpArr,int m, int n){
    printf("print dpArr:\n[");
    for (int i = 0; i < m; i++)
    {
        printf("\n\t[");
        for (int j = 0; j < n; j++)
        {
            if(j == 0){
                printf("%d",*(*(dpArr+i)+j));
            }else{
                printf(",%d",*(*(dpArr+i)+j)); 
            }
        }
        if(i == m-1){
            printf("]");
        }else{
            printf("],"); 
        }
    }
    printf("\n]\n");
}

int uniquePaths(int m, int n){
    // 1. 构造dp
    int** dpArr = (int**) malloc(sizeof(int*)*(m));
    for (int i = 0; i < m; i++)
    {
        dpArr[i] = (int*) malloc(sizeof(int)*(n));
    }
    // 初始化
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(dpArr+i)+j) = 0;
        }
    }
    //printDpArr(dpArr,m,n);
    
    for (int i = 0; i < n; i++)
    {
        *(*(dpArr)+i) = 1;
    }
    for (int i = 0; i < m; i++)
    {
        *(*(dpArr+i)) = 1;
    }
    // printDpArr(dpArr,m,n);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            *(*(dpArr+i)+j)=*(*(dpArr+i-1)+j)+*(*(dpArr+i)+j-1);
        }
    }
    printDpArr(dpArr,m,n);
    printf("result: %d\n",*(*(dpArr+m-1)+n-1));
    return *(*(dpArr+m-1)+n-1);
}