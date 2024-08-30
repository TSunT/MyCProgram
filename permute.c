#include "hello.h"

#define MAX_SIZE  65536

// 访问标记数组
int* vis;

void backtrack(int** result, int* nums, int level, int* colNums, int numsSize, int* returnSize){
    // 当 level = numsSize 拼接后更新 result 
    if(level == numsSize){
        int* tmp =(int*) malloc(sizeof(int)*(numsSize));
        memcpy(tmp,colNums,sizeof(int)*(numsSize));
        result[(*returnSize)++] = tmp;
        return;
    }
    // 获取本层遍历数组
    for (int i = 0; i < numsSize; i++)
    {
        if(*(vis+i)){
            // 已访问
            continue;
        }
        *(vis+i)=1;
        *(colNums+level) = *(nums+i);
        // printf("pos: %d val:%d\t",i,*(colNums+level));
        backtrack(result,nums,level+1,colNums,numsSize,returnSize);
        //*(colNums+level) = 0;
        *(vis+i)=0;
    }
    
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** result = (int**) malloc(sizeof(int*)*MAX_SIZE);
    int* colArr = (int*) malloc(sizeof(int)*MAX_SIZE);
    vis = (int*) malloc(sizeof(int)*(numsSize));
    memset(vis,0,sizeof(int)*numsSize);
    backtrack(result,nums,0,colArr,numsSize,returnSize);

    *returnColumnSizes = (int*) malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}

// 将结果打印到控制台
void printTwoDimInt(int** source,int** returnColumnSizes, int* returnSize){
    printf("\n[");
    for (int i = 0; i < *returnSize; i++)
    {
        if(i == 0){
            printf("[");
        }else{
            printf(", ["); 
        }
        int* row = *(source+i);
        int colNum = (*returnColumnSizes)[i];
        for (int j = 0; j < colNum; j++)
        {
            if(j == 0){
                printf("%d",*(row+j));
            }else{
                printf(",%d",*(row+j));
            }
        }
        printf("]");
    }
    printf("]");
}

void testPermuteFunc(){
    int* numArr = (int*) malloc(sizeof(int)*MAX_SIZE);
    int size = 4;
    for (int i = 0; i < size; i++)
    {
        *(numArr+i) = i+1;
    }
    int** returnColumnSize = (int**) malloc(sizeof(int*)*MAX_SIZE);
    int* returnSize = (int*) malloc(sizeof(int));
    int** result = permute(numArr, size,returnSize,returnColumnSize);
    // print result
    if(result != NULL && returnSize != NULL && returnColumnSize != NULL){
        printTwoDimInt(result,returnColumnSize,returnSize);
    }else{
        printf("result exist NULL!");
    }
}