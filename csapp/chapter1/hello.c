

# include <stdio.h>
# include <string.h>

typedef unsigned char *byte_pointer;  // 定义类型

// size_t 为了增强程序的可移植性，便有了size_t ，不同系统上，定义size_t可能不一样。经测试发现，在32位系统中size_t是4字节的，在64位系统中，size_t是8字节的
// 打字节中存储的16进制数据
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);  // 数组表示法来引用指针
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));  // 强制转换数据类型 byte_pointer 为字节序列
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

// 当函数不允许接受参数时必须用void 来限定函数参数，限定了函数的参数类型为void后函数不能有参数；如：int fun(void)；
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
    // 地址存储： 大端法和小端法
    int ival = 12345;  // 0x3039
    show_int(ival);

    float fval = (float) ival;
    show_float(fval);

    int *pval= &ival;  // void * 为 "不确定类型指针"
    show_pointer(pval);

    int aa = 2;
    int *bb ;
    bb = &aa;
    printf("%d\n", aa);
    printf("%p\n", bb);
    printf("%d\n", *bb);

    const char *s = "12345bc";
    show_bytes((byte_pointer) s, strlen(s));
    
}


/*
%a  浮点数、十六进制数字和p-记数法（c99
%A  浮点数、十六进制数字和p-记法（c99）
%c  一个字符(char)
%C  一个ISO宽字符
%d  有符号十进制整数(int)（%ld、%Ld：长整型数据(long),%hd：输出短整形。）　
%e  浮点数、e-记数法
%E  浮点数、E-记数法
%f  单精度浮点数(默认float)、十进制记数法（%.nf  这里n表示精确到小数位后n位.十进制计数）
%g  根据数值不同自动选择%f或%e．
%G  根据数值不同自动选择%f或%e.
%i  有符号十进制数（与%d相同）
%o  无符号八进制整数
%p  指针
%s  对应字符串char*（%s = %hs = %hS 输出 窄字符）
%S  对应宽字符串WCAHR*（%ws = %S 输出宽字符串）
%u  无符号十进制整数(unsigned int)
%x  使用十六进制数字0xf的无符号十六进制整数　
%X  使用十六进制数字0xf的无符号十六进制整数
%%  打印一个百分号

%I64d 用于INT64 或者 long long
%I64u 用于UINT64 或者 unsigned long long
%I64x 用于64位16进制数据
*/