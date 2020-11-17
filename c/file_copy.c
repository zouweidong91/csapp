

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



#define IN 1
#define OUT 0
// 统计行数  单词数 字符数
int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}