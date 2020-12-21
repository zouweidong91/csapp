

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);  // 函数原型


int main(int argc, char *argv[]){
    char line[MAXLINE];
    long lineno = 0;

    int c, except = 0, number = 0, found = 0;

    while (--argc >0 && (*++argv)[0] == '-'){
        printf("argv1: %s\n", *argv);
        while(c = *++argv[0])   // []的优先级高于 ++
            {
            printf("argv2: %c\n", c);
            switch (c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find:illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }}
        }
    if (argc != 1)
        printf("usage: find -x -n pattern\n");
    else
        while(getline(line, MAXLINE) >0){
            lineno++;
            printf("argv: %s\n", *argv);
            if ((strstr(line, *argv) != NULL) != except){
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}



int getline(char *s, int lim){
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && c!= '\n' && --lim > 0)
        s[i++] = c;
        // {
        //     *s = c;
        //     s++;
        // }
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}


/*
gcc grep.c -o grep.o
grep.o -nx abc
*/