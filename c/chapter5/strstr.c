
/* 5.11
函数本身不是变量，但是可以定义指向函数的指针

排序函数：
    在指定可选参数-n的情况下，该函数将按照数值大小而非字典顺序对输入文本进行排序
*/

# include <stdio.h>
# include <string.h>

int main(){
    const char haystack[20] = "RUNOOBcdc";
    const char needle[10] = "NOOB";

    char *ret;

    ret = strstr(haystack, needle);

    printf("%p\n", ret);  // 打印内存地址
    printf("%s\n", ret);  // NOOBcdc
    return 0;
}