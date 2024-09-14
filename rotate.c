#include "hello.h"

#define MAX_SIZE 5

void printResult(int** matrix, int matrixSize, int* matrixColSize){
    printf("\n the current matrix is: [\n");
    for (int i = 0; i < matrixSize; i++)
    {
        if(i == 0){
            printf("\t [");
        }else{
            printf("\t,["); 
        }
        for (int j = 0; j < *(matrixColSize+i); j++)
        {
            if(j==0){
                printf("%d",*(*(matrix+i)+j));
            }else{
                printf(",%d",*(*(matrix+i)+j));
            }
        }
        printf("]\n");
    }
    printf("]\n");
}

//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp;
    for (int i = 0; i < matrixSize/2; i++)
    {
        for (int j = i; j < matrixSize - i - 1; j++)
        {
            // printf("======>i: %d, j: %d\n",i,j);
            temp = *(*(matrix+(matrixSize-j-1))+i);
            *(*(matrix+(matrixSize-j-1))+i)=*(*(matrix+(matrixSize-i-1))+matrixSize-j-1);
            *(*(matrix+(matrixSize-i-1))+matrixSize-j-1)=*(*(matrix+j)+matrixSize-i-1);
            *(*(matrix+j)+matrixSize-i-1)=*(*(matrix+i)+j);
            *(*(matrix+i)+j) = temp;
            // printf("%d,%d\n",i,j);
            // printf("%d,%d\n",j,matrixSize-i-1);
            // printf("%d,%d\n",matrixSize-i-1,matrixSize-i-j-1);
            // printf("%d,%d\n",matrixSize-j-1,0);
            // printResult(matrix,MAX_SIZE,matrixColSize);
        }
    }
}

void testRotate(){
    // 1. define matrix and initialization
    int** matrixPtr = (int**) malloc(sizeof(int*)*MAX_SIZE);
    int temp = 1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        matrixPtr[i] = (int*) malloc(sizeof(int)*MAX_SIZE);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            *(*(matrixPtr+i)+j) = temp++;
        }
        
    }
    int* matrixColPtr = (int*) malloc(sizeof(int)*MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        *(matrixColPtr+i) = MAX_SIZE;
    }
    

    printResult(matrixPtr,MAX_SIZE,matrixColPtr);
    // 2.rotate the matrix
    rotate(matrixPtr,MAX_SIZE,matrixColPtr);
    // 3.打印结果
    printResult(matrixPtr,MAX_SIZE,matrixColPtr);
}