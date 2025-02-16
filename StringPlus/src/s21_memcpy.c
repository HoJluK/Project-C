#include "s21_string.h"

void *s21_memcpy (void *dest, const void *src, s21_size_t n){
    char *destination = (char*)dest;
    char *source = (char*) src; 
    for (s21_size_t i = 0; i < n; i++){
        destination[i] = source[i];
    }
    return dest;
}

// int main() {
//     char dest[10];
//     char *src = "hello";
//     size_t n = 6;
//     strncpy(dest,src,n);
//     for(int i = 0; i < n; i++){
//         printf("%c",dest[i]);
//     }
//     return 0;
// }