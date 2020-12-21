// 命令行参数  argc参数技术   argv 参数向量 ANSI标准要求argv[argc]必须是空指针0
// echo  heool, world       argv[0], argv[1], argv[2] echo  hello  world
# include <stdio.h>

// 数组下表实现
int array_main(int argc, char *argv[]){
    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
}

// 指针实现方式
int main(int argc, char *argv[]){
    while (--argc > 0)
    {
        // argv第一个值是函数名称自身
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
        // printf((argc > 1) ? "%s ": "%s", *++argv);
    }
    printf("\n");
    return 0;
    
}

// gcc echo1.c -o echo1.o
// echo1.o hello world