
#include <stdio.h>
#include <ctype.h>


#define MAXLINE 1000


int main(){
    double sum, atof(char s[]);
    char line[MAXLINE];
    // double sum;
    int getline(char line[], int max);

    sum = 0;

    while(getline(line, MAXLINE) > 0){
        printf("\t%g\n", sum += atof(line));  
        /*atof与调用它的main函数不在同一个源文件中时，
        如果不对atof函数提起按double声明，上下文会认为stof只是一个普通安徽念书，该函数返回值被假定为int，*/
    }
    return 0;
}


int getline(char s[], int lim){
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
    {
        s[i++] = c;
    }

    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


double atof(char s[]){
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)  /*跳过空白符*/
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}


/*字符串转整数*/
int atoi(char s[]){
    double atof(char s[]);  //函数原型声明
    return (int)atof(s);
}