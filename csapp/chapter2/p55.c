
# include <stdio.h>

typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start, size_t len){

    size_t i;
    for (i = 0; i < len; i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_short(short x){
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x){
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(double x){
    show_bytes((byte_pointer)&x, sizeof(double));
}


int main(){
    double num = 1114.2323;
    int num_i = (int)num;
    short num_s = (short)num;
    long num_l = (long)num;
    double num_d = (double)num;

    show_int(num_i);
    show_short(num_s);
    show_long(num_l);
    show_double(num_d);
}
