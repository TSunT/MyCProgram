#include "hello.h"

int maxArea(int* height, int heightSize){
    if(heightSize <=1 ){
        return 0;
    }
    int start = 0, end = heightSize - 1, size = 0;
    while (start < end)
    {
        /* code */
        printf("------ loop start -------\n");
        printf("start = %d\n",*(height+start));
        printf("end = %d\n",*(height+end));
        
        printf("offset = %d\n",end-start);

        int currentSize = 0;
        if(*(height+start) >= *(height+end)){
            currentSize = (end-start)* *(height+end);
        }else{
            currentSize = (end-start)* *(height+start);
        }
         printf("currentSize = %d\n",currentSize);
        // 如果头指针大于尾指针 尾指针减一
        if (*(height+start) > *(height+end))
        {
            /* code */
            printf("end--\n");
            end--;
        }
        // 如果头指针小于尾指针 尾指针加一
        // if (*(height+start) < *(height+end))
        else{
            /* code */
            printf("start++\n");
            start++;
        }

        // 更新面积
        if(size < currentSize){
            size = currentSize;
        }
        printf("------ loop end -------\n");
    }
    
    return size;
}