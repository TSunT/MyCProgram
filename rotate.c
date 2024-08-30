#include "hello.h"

#define MAX_SIZE 3

//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    
}

void printResult(int** matrix, int matrixSize, int* matrixColSize){
    printf("[");
    for (int i = 0; i < matrixSize; i++)
    {
        if(i == 0){
            printf("[");
        }else{
            printf(", ["); 
        }

        printf("]");
    }
    printf("]");
}

void testRotate(){
    // 1. define matrix and initialization
    int** matrixPtr = malloc(sizeof(int*)*MAX_SIZE);
    int temp = 1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int* rowPtr = matrixPtr[i];
        *rowPtr = malloc(sizeof(int)*MAX_SIZE);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            *(rowPtr+j) = temp++;
        }
        
    }

    // 3.打印结果
    
}