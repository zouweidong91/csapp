
# 程序的机器级表示

*  指定编译时优化等级 -Og
编译生成汇编代码 mstore.s
gcc -Og -S mstore.c

编译并汇编生成目标代码文件 mstore.o
gcc -Og -c mstore.c


* gdb调试工具 gdb+mstore.o
gdb mstore

* 反编译器 生成类似汇编格式的代码
objdump -d mstore.o


* 链接器
对一组目标代码文件运行链接器，生成可实际执行的代码。这组目标代码文件必须包含一个main函数。
gcc -Og -o prog.o main.c mstore.c

* ATT 汇编代码格式

* 数据传送指令  movl  movabsq  movezbl
%rsp寄存器对应操作指令:  pushq popq 

参数是通过寄存器传递给函数的
x86-64不允许指令将数据从内存移动到内存

* 一元和二元操作符
imulq $16, (%rax, %rdx, 8)    // 目的地是一个内存地址，需要先计算出该内存地址，再进行计算，并保存至该内存地址
(%rax, %rdx, 8) --> 8*(%rdx)+(%rax)  寄存器在括号内时，是一个内存地址，需要从地址拿具体的值


* 字符串编码
ASCII编码    一个字节。 Python2中默认的编码格式是 ASCII 格式
GBK编码     汉字的GBK编码占用两字节.

unicode编码  
    将所有语言统一到一套编码中。 一律以2个字节编码，或者也有4个字节的
    占用空间会大一些，一般只用于内存中的编码使用
    中：\u4e2d  (用十六进制表示就是 0x4e2d)
    utf-8 是为了实现unicode 的传输和存储的。因为它可变长，存英文时候可以节省大量存储空间。传输时候也节省流量，所以更加 “ international ”

UTF-8编码
    英文一个字节，汉字3个字节

    但是如果内容全是英文，unicode编码比ASCII需要多一倍的存储空间，同时如果传输需要多一倍的传输。所以出现了可变长的编码“utf-8"，把英文变长一个字节，汉字3个字节。特别生僻的变成4-6字节。
    utf8编码在文件存储或网络传输的时候的优势就特别大，但是如果实在内存种的时候字符串有的占1个字节，有的2个，就很不好捉摸
    所以unicode编码虽然占用空间，但是在编程的时候，在内存里面处理的时候比会utf8更简单，因为它们都是一样的长度

    它是一种可变长度的编码. 然后UTF-8是按8bit长度的一个可变长的多 code unit编码方式.
    编码规则: https://www.zhihu.com/question/294660079/answer/2504503619


* 算数右移和算数右移
逻辑左移=算数左移，右边统一添0 
逻辑右移，左边统一添0 
算数右移，左边添加的数和符号有关，左侧添加符号位。即正数添0，负数添1。
如果负数要进行逻辑右移，可将其转换为unsigned类型。

* 操作数
leaq指令不改变任何条件码，它是用来进行地址计算的



