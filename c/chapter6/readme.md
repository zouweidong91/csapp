
* 在所有运算符中，一下4个运算符优先级最高，它们同操作数的结合也最紧密
    结构运算符 . ->
    () []

struct {
    int len;
    char *str;
} *p;
定义了一个指向相应结构的指针p;

表达式
++p->len
将增加len的值，而不是增加p的值

*p->str++  先读取指针str指向的对象，再将str加1
(*p->str)++ 将指针str指向的对象加1


## 自引用
struct t{
    struct s *p;  // p指向一个s结构
}

struct s {
    struct t *q;  // q指向一个t结构
}
