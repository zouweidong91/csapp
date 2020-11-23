
// 后缀表示法
// 1 2 - 4 5 + *

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /*操作数或运算符最大长度*/
#define NUMBER '0' /*标识找到一个数*/

int getop(char []);
void push(double);
double pop(void);

int main(){
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF){
        printf("type: %d\n", (type-'0'));
        switch (type){
            case NUMBER:
                push(atof(s)); //每个字符都以空格或制表符隔开？
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero division\n");
                break;
            default:
                printf("error: unknown command");
                break;
            }
    }
    return 0;
}



#define MAXVAL 100

int sp = 0; //下一个空闲栈位置
double val[MAXVAL]; // 栈值


void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if(sp > 0)
        return val[--sp];
    else
        printf("error: stack empty \n");
    return 0.0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/*获取下一个运算符或操作数*/
int getop(char s[]){
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if(c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    int a;
    if (bufp > 0)
        return buf[--bufp];
    else{
        a = getchar();
        return a;
    }


    // return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else{
        printf("ungetch: %d\n", c);
        buf[bufp++] = c;
    }

}
