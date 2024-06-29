#include "hello.h"

/**
 * 47. 全排列 2
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int** result, int level, int* levelNums, int* numsSize, int* returnSize){
    // 当 level = numsSize 拼接后更新 result 
    if(level == *numsSize){
 
        return;
    }
    // 获取本层遍历数组
    for (int i = 0; i < *numsSize-level; i++)
    {
        /* code */
    }
    
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;

    return NULL;
}