#include "hello.h"

int sum(int a, int b){
    return a+b;
}

int hellomain(){
    printf("Hello, World!\n");
    int a = 0, b = 0;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a= %d, b= %d, a+b=%d\n",a,b,a+b);
    // int a,b;
    // printf("hello world!!!\n");
    // printf("input var1>");
    // scanf("%d", &a);
    // printf("\n");
    // printf("input var2>");
    // scanf("%d",&b);
    // printf("add result is: %d \n" ,sum(a,b));
    // 11. 盛最多的水
    // int aArr[10] = {4,4,2,11,0,11,5,11,13,8};
    // int res = maxArea(aArr,10);
    // printf("the result is %d\n", res);
    // 24. 两两交换链
    // testSwapPairs();
    // 47.全排列 2
    testPermuteFunc();
    return 0;
}