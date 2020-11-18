
#include <stdio.h>

#define MAXLINE 1000

// 类型转换  将字符串转换为响应整数

// int atoi(char s[]){
//     int i, n;

//     n = 0;
//     for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
//         n = n * 10 + (s[i] - '0');
//     return n;
// }


// int lower(int c){
//     if (c >= 'A' && c <= 'Z')
//         return c + 'a' - 'A';
//     else
//         return c;
// }


// int type_transfer(){
//     char line[MAXLINE];
//     int num;

//     int c, i;
//     for (i = 0; (c = getchar()) != EOF && i < MAXLINE -1; ++i)
//         line[i] = lower(c);
//     line[i] = '\0';
//     printf("str %s\n", line);

//     num = atoi(line);
//     printf("int num %d\n", num);
// }


// int main(){
//     char s[100] = "n";
//     char t[] = "a1ss2dcsdc";

//     int i, j;
//     i = j = 0;
//     while(s[i] != '\0')
//         i++;

//     while((s[i++] = t[j++]) != '\0')
//         ;

//     printf("%s\n", s);
// }


void dectobin(int n);

int main()
{
    int x=0;
    scanf("%d",&x);//只能正数
	dectobin(x);
	printf("\n");
    return 0;

}


void dectobin(int n){
    if(n/2>0){
        dectobin(n/2);
        printf("%d", n%2);
    }
    else{
        printf("%d", n);
    }
}
