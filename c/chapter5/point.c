
// 指针数组的初始化
// month_name函数  返回第n个月份的名字
// 第i个字符串的所有私服存储在存储器的某个位置，指向它的指针存储在name[i]中。
// 由于没有指定数组长度，编译器编译时对初值个数进行统计，并将这一准确数字填入数组的长度
char *month_name(int n){
    static char *name[] = {
        "Illegal month", "January", "February", "Marth",
        "Aprial", "May", "June", "July", "August", "September", "October",
        "November", "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}

// 指针与多维数组

void dummy1(){
    char *name[] = {
        "Illegal month", "January", "February", "Marth"
    };
    // 编译器为其分配了4个不等长数组和4个指针的存储空间

    char aname[][15] = {
        "Illegal month", "January", "February", "Marth"
    };
    // 编译器分配了4个长度为15的字符数组
}

