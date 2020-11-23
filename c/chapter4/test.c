/* 实现功能：输入后缀表达式，以换行结束，计算四则运算结果 */
/* 这种后缀表示法只需要一个栈就可以了,遇到符号则弹运算数,但是中缀就不一样 */
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
typedef int Status;
typedef char SElemType;
typedef struct
{
    SElemType *top;
    SElemType *base;
    int stacksize;
} SqStack;
Status InitStack(SqStack *s)
{
    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->base) exit(OVERFLOW);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status Push(SqStack *s, SElemType e)
{
    if (s->top - s->base == s->stacksize)
    {
        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREAMENT) * sizeof(SElemType));
        if (!s->base) exit(OVERFLOW);
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREAMENT;
    }
    s->top++;
    *(s->top) = e;
    return OK;
}
Status Pop(SqStack *s, SElemType *e)
{
    if (s->top == s->base) exit(OVERFLOW);
    *e = *(s->top);
    s->top--;
    return OK;
}
Status Empty(SqStack s)
{
    if (s.top - s.base == 0)
        return OK;
    else
        return ERROR;
}
int main()
{
    SqStack OPND; //OPTR是运算符 OPND是运算数
    char c, num1, num2;
    InitStack(&OPND);
    while((c = getchar()) != '\n')
    {
        switch(c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            Push(&OPND, c - '0');
            break;
        case '+':
            Pop(&OPND, &num2);
            Pop(&OPND, &num1);
            Push(&OPND, num1 + num2);
            break;
        case '-':
            Pop(&OPND, &num2);
            Pop(&OPND, &num1);
            Push(&OPND, num1 - num2);
            break;
        case '*':
            Pop(&OPND, &num2);
            Pop(&OPND, &num1);
            Push(&OPND, num1 * num2);
            break;
        case '/':
            Pop(&OPND, &num2);
            Pop(&OPND, &num1);
            Push(&OPND, num1 / num2);
            break;
        default:
            break;
        }
    }
    while(!Empty(OPND))
    {
        Pop(&OPND, &c);
        printf("%d ", c);
    }
    return OK;
}
