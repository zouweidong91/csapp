


#include <stdio.h>

// 符号常量，用大写，与变量区别
#define LOWER 0
#define UPPER 300
#define STEP 20


int main()
{
    int fahr;
    for (fahr = LOWER; fahr < UPPER; fahr = fahr + STEP){
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}