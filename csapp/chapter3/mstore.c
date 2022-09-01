

long mult2(long, long);
void multstore(long x, long y, long *dest){
    // 计算结果保存至dest指针中
    long t = mult2(x, y);
    *dest = t;
}


