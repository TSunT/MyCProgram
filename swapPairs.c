#include "hello.h"

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

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* startNode = head ->next;  // 新的头
    struct ListNode* previousNode = head;  // 保存上次交换第二节点的地址
    struct ListNode* firstNode = head; // 第一个节点
    struct ListNode* secondNode = NULL; // 第二个节点
    struct ListNode* tempNode = NULL;  // 保存下次循环的地址
    while (firstNode != NULL && firstNode -> next != NULL) {
        secondNode = firstNode->next;
        tempNode = secondNode->next;
        // if(previousNode != NULL) {
        //     previousNode->next = secondNode;
        // }
        previousNode->next = secondNode;
        previousNode = firstNode;
        secondNode->next = firstNode;
        firstNode->next = tempNode;
        firstNode = tempNode;
    }
    return startNode;
}

void testSwapPairs(){
    // 1. 构建链表结构
    int a[10] = {4,1,2,11,0,11,5,11,13,8};;
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *head = temp;
    for (int i = 0; i < 10; i++)
    {
        int newVal = a[i];
        struct ListNode *currentNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        currentNode->val = newVal;
        currentNode->next = NULL;
        temp->next = currentNode;
        temp = temp->next; 
    }
    
    // 2. 执行交换
    temp = swapPairs(head->next);
    // 3. 遍历链表
    printf("[");
    while (temp != NULL) {
        if(temp -> next != NULL){
            printf("%d, ", temp->val);
        }else{
           printf("%d", temp->val); 
        }
        temp = temp -> next;
    }
    printf("]");
}