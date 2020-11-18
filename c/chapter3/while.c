
#include <stdio.h>
#include <ctype.h>


int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; isdigit(s[i]); i++)
        n = n * 10 + (s[i] - '0');
    return sign * n;
}

int main(){
    char c[] = "  -10354";
    int rst;

    rst = atoi(c);
    printf("%d", rst);
}

void reverse(char s[]){
    int i, j, c;

    // 此处 j = strlen(s)-1  最后的'\0' 依然保留，没有参与reverse
    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}