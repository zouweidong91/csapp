

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }
    }
    return found;
}


int getline(char s[], int lim){
    int c, i;
    i = 0;

    while((c = getchar())!= EOF && c != '\n' && --lim > 0)
        s[i++] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

// 一个字符串是否包含再另一个字符串中
int strindex(char s[], char t[]){
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
            ;
        if (k > 0 &&t[k] == '\0')
            return i;
    }
        return -1;
}

