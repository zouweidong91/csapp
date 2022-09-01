
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



