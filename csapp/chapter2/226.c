
# include <stdio.h>
# include <string.h>
# include <stdint.h>

typedef unsigned char *byte_pointer;  // 定义类型  将底层位表示转换为字符序列

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}


int main() {
    // 扩展一个数字的位表示
    short sx = -12345;  // 16位
    unsigned short usx = sx;  // 2**16-12345 = 53191
    int x = sx;  // 32位
    // unsigned int ux = usx; // 从16位扩展到32位  等价于 (unsigned)(unsigned short)sx
    unsigned int ux = sx; // 等价于 (unsigned)(int)sx

    printf("sx = %d: \t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %u: \t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x = %d: \t", x);
    show_bytes((byte_pointer)&x, sizeof(int));
    printf("ux = %u: \t", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned));
}

