#include "hello.h"

void printDpArrObstacles(int** dpArr,int m, int n){
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

/**
 *  一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *  机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
 *  现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *  网格中的障碍物和空位置分别用 1 和 0 来表示。
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {

    int n = obstacleGridSize, m = obstacleGridColSize[0];

    // 1. 构造dp
    int** dpArr = (int**) malloc(sizeof(int*)*(n));
    for (int i = 0; i < n; i++)
    {
        dpArr[i] = (int *) malloc(sizeof(int)*m);
        memset(dpArr[i],0,sizeof(int)*m); // 初始化函数
    }
    // printDpArrObstacles(dpArr,n,m);

    for (int i = 0; i < n; i++)
    {
        if(**(obstacleGrid+i)!=1)
        {
            *(*(dpArr+i)+0) = 1;
        }
        if(i>0 && **(obstacleGrid+i-1)){
             *(*(dpArr+i)+0) = 0; // 障碍出现在第一列上
             break; // 后续不可能为1
        }
    }
    for (int i = 0; i < m; i++)
    {
        if(*(*(obstacleGrid)+i)!=1)
        {
            *(*(dpArr+0)+i) = 1;
        }
        if(i>0 && *(*(obstacleGrid)+i-1)){
            *(*(dpArr+0)+i) = 0; // 障碍出现在第一列上
             break; // 后续不可能为1
        }
    }
     printDpArrObstacles(dpArr,n,m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(!*(*(obstacleGrid+i)+j))
            {
                dpArr[i][j] = dpArr[i-1][j]+dpArr[i][j-1];
            }
        }
        
    }
    printDpArrObstacles(dpArr,n,m);

    return dpArr[n-1][m-1];
}

int testUniquePathsWithObstacles(){
    // int obstacleGrid[3][3] = {0,0,0,0,1,0,0,0,0};
    int **obstacleGridPtr = (int *) malloc(sizeof(int*)*3);
    for (int i = 0; i < 3; i++)
    {
        obstacleGridPtr[i]= (int *) malloc(sizeof(int)*3);
        memset(obstacleGridPtr[i],0,sizeof(obstacleGridPtr[i]));
    }
    *(*(obstacleGridPtr+1)+1) = 1;
    //*(*(obstacleGridPtr+0)+1) = 1;
    *(*(obstacleGridPtr+1)+0) = 1;
    
    int obstacleGridSize = 3;
    int obstacleGridColSize[3];
    // memset(obstacleGridColSize,3-0,sizeof(obstacleGridColSize));
    for (int i = 0; i < obstacleGridSize; i++)  
    {
        *(obstacleGridColSize+i) = 3;
    }
    printf("result: %d\n",uniquePathsWithObstacles(obstacleGridPtr,obstacleGridSize,obstacleGridColSize));
    return 0;
}