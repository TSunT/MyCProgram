#include "hello.h"

int changeUpper2Lower(){

    // 1. 输入一个字符a
    char a;
    printf("input a charachar >>");
    scanf("%c",&a);
    // 2. 判断输入是否合法 A～Z ，超过范围返回 0
    if(a<'A'||a>'Z'){
        printf("input charachar is invaild!");
        return 0;
    }
    // 3. 进行字符转换 
    int diff = a - 'A';
    char result = 'a' + diff;
    // 4. 输出转换结果
    printf("change result is: %c\n", result);
    return result;
}
