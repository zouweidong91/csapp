

## 函数 变量

最简单的函数, 开发期间用以保留位置
dummy() {}

如果函数定义中省略了返回值类型，默认为int类型。

c语言不允许函数中定义函数，因此，函数本身是外部的

外部变量：函数外部定义的变量

外部变量于静态变量 不显式初始化时默认为0；其初始化表达式必须时常量表达式
自动变量和寄存器变量可以包含此前已经定义过的值



## 静态变量
static int bufp=0; 
该变量今提供源文件中的函数使用。其他文件中函数不能访问。

static也可以用于函数，函数名除了对该函数声明所在的文件可见外，其他文件都无法访问。

static也可以用于声明内部变量。同自动变量一样，时某个函数内部的变量。但和自动变量不同的是，不管所在函数是否被调用，它一直存在。换句话说，static类型的内部变量是一种只在某个函数中使用但一直占据存储空间的变量

## 初始哈
Int数组
int days[5] = {31, 28, 31}
未被初始化的元素被默认为0

char数组 2种
char pattern[] = "ould"
char pattern[] = {'o', 'u', 'l', 'd', '\0'}
两种方式等价 长度为5



