#include "../s21_string.h"

void *s21_memset (void *str, int ch, size_t n){
    unsigned char *function_str = (unsigned char*) str;
    for (size_t i = 0; i < n; i++){
        function_str[i] = (unsigned char)ch;
    }
}

// int main() {
//     int ch = 'a';
//     char dest[] = "hello";
//     char dest2[] = "hello";
//     s21_memset(dest, ch, 4);
//     char *res = memset(dest2, ch, 4);
//     printf("dest: %s\n", dest);
//     printf("dest2: %s\n", res);
//     return 0;
// }