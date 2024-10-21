#ifndef _HELLO_H_
#define _HELLO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

// 11. 盛最多的水
int maxArea(int* height, int heightSize);
// 24. 两两交换链表中的节点
void testSwapPairs();
/**
 * 47. 全排列 2
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
 */
void testPermuteFunc();
/**
 * 48. 旋转图像
 */
void testRotate();

/**
 * 61. 旋转链表
 */
void testRotateRight();

/**
 * 62. 不同路径
 */
int uniquePaths(int,int);

/**
 * 63. 不同路径 II (带阻碍)
 */
int testUniquePathsWithObstacles();

/**
 * 207. 课程表
 */
// void testCanFinish();

/**
 * 大写字母转小写字母
 */
int changeUpper2Lower();
#endif