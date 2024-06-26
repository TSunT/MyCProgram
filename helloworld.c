#include "hello.h"

int sum(int a, int b){
    return a+b;
}

int main(){
    // int a,b;
    // printf("hello world!!!\n");
    // printf("input var1>");
    // scanf("%d", &a);
    // printf("\n");
    // printf("input var2>");
    // scanf("%d",&b);
    // printf("add result is: %d \n" ,sum(a,b));
    int aArr[10] = {4,4,2,11,0,11,5,11,13,8};
    int res = maxArea(aArr,10);
    printf("the result is %d\n", res);
    return res;
}