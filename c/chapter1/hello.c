
#include <stdio.h>  // 包含标准输入输出库

int main()  //每个程序都是从main函数的起点开始执行
{
    printf("hello, world\n");
    // int fahr, celsius;
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        // celsius = 5 * (fahr - 32) /9;
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        // printf("%d\t%d\t\n", fahr, celsius);
        printf("%3.0f %.1f\n", fahr, celsius);
        fahr = fahr + step;
    };
}


// gcc hello.c -o hello.o
// hello.o