
# include <stdio.h>
# include <string.h>
# include <stdint.h>

// 判定无符号加法是否溢出
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    return sum >= x;
}

// 判定补码加法是否溢出  赋值运算符优先级低
int tadd_ok(int x, int y) {
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}


int main() {
    int32_t x;
    uint64_t y;

    printf("x = %d, y = %lu\n", x, y);

    int x1 = -1;
    unsigned u = 2147483648;
    printf("x = %u = %d\n", x1, x1); // %u  无符号十进制整数(unsigned int)
    printf("x = %u = %d\n", u, u);
}
