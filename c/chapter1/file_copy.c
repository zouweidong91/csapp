

#include <stdio.h>
// EOF  enter  ctrl+z   enter


// 复制输入到输出
// char 一个字节 8位  int 16位
// int main()
// {
//     int c;
//     c = getchar(); //通过键盘输入
//     while (c != EOF)
//     {
//         putchar(c); //可以与printf交替使用
//         c = getchar();
//     }
    
// }


// int main()
// {
//     int c;
//     while ((c =  getchar()) != EOF)
//     // 赋值表达式的圆括号不能省略 因为!=优先级比赋值运算符的优先级高
//     {
//         putchar(c); //可以与printf交替使用
//         printf(2 != 2);
//     }
    
// }

// int main()
// {
//     printf("EOF is %d\n", EOF);
//     return 0;
// }

// int main()
// {
//     long nc;
//     nc = 0;
//     while(getchar() != EOF){
//         ++nc;
//         printf("%ld\n", nc);
//     }
// }

// int main(){
//     double nc;
//     for (nc = 0; getchar() != EOF; ++nc)
//     {
//         ;
//     }
//     printf("%.0f\n", nc);
// }

// int main(){
//     int c, nl;
    
//     nl = 0;
//     while ((c = getchar()) != EOF)
//     {
//         if (c == '\n'){
//             ++nl;
//         }
//     }
//     printf("%d\n", nl);
// }



// #define IN 1
// #define OUT 0
// // 统计行数  单词数 字符数
// int main(){
//     int c, nl, nw, nc, state;
//     state = OUT;
//     nl = nw = nc = 0;
//     while((c = getchar()) != EOF){
//         ++nc;
//         if (c == '\n')
//             ++nl;
//         if (c == ' ' || c == '\n' || c == '\t')
//             state = OUT;
//         else if (state == OUT){
//             state = IN;
//             ++nw;
//         }
//     }
//     printf("%d %d %d\n", nl, nw, nc);
// }



// // 声明语句  表明有2个镇红星参数 并返回int 这种声明成为函数原型   参数名是可选项
// int power(int m, int n);
// /// int power(int, int);

// int main(){
//     int i;
//     for (i = 0; i < 10; ++i)
//         printf("%d %d %d \n", i, power(2, i), power(-3, i));
//     return 0;
//     // return 表达式
// }


// int power(int base, int n){
//     // 声明部分
//     // 语句部分
//     int i, p;
//     p = 1;
//     for (i = 1; i <= n;++i)
//         p = p * base;
//     return p;
// }



// #define MAXLINE 1000


// int getline(char s[], int lim){
//     int c, i;
//     for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1;  ++i)
//         s[i] = c;
//     if (c == '\n'){
//         s[i] = c;
//         ++i;
//     }
//     s[i] = '\0'; // '\0'拷贝到字符串的末尾 标记字符串的结束，这一约定已经被c采用 程序检测到'\0'后 ，自动数组将后边的元素全部截去
//     printf("getline %s", s);
//     return i;
// }

// void copy(char to[], char from[]){
//     int i;
//     i = 0;
//     while ((to[i] = from[i]) != '\0')
//     {
//         ++i;
//     }
// }

// int getline(char line[], int maxline);
// void copy(char to[], char from[]);

// int main(){
//     int len;
//     int max;
//     char line[MAXLINE];
//     char longest[MAXLINE];

//     max = 0;

//     while ((len = getline(line, MAXLINE)) > 0)
//         if (len > max){
//             max = len;
//             copy(longest, line);
//         }
//     if (max > 0)
//         printf("%s", longest);
//     return 0;
// }



// 外部变量

#define MAXLINE 1000

// 程序开始时  定义了各外部变量  并分配了存储单元
int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline(void);
void copy(void);

int getline(){
    int c, i;
    // 在函数内部 使用extern 类型声明  此时只说明变量的性质 不分配存储单元
    extern char line[];
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAXLINE - 1; ++i)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0'; // '\0'拷贝到字符串的末尾 标记字符串的结束，这一约定已经被c采用 程序检测到'\0'后 ，自动数组将后边的元素全部截去
    // printf("getline %s", line);
    return i;
}

void copy(){
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}


int main(){
    int len;
    extern int max;
    extern char longest[];

    max = 0;

    while ((len = getline()) > 0)
        if (len > max){
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

