#ifndef _HELLO_H_
#define _HELLO_H_
#include <stdio.h>
#include <stdlib.h>
// 11. 盛最多的水
int maxArea(int* height, int heightSize);
// 24. 两两交换链表中的节点
void testSwapPairs();
/**
 * 47. 全排列 2
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
#endif