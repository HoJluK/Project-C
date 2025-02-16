#include "s21_string.h"

char* s21_strncat (char *dest, const char* str, s21_size_t n){
    s21_size_t count = 0;
    while (dest[count]!='\0'){
        count++;
    }
    for (s21_size_t i = 0; i < n; i++){
        dest[count + i] = str[i];
    }
return dest;
}

// int main(){
//     char des[50] = "hello";
//     char des2[50] = "hello";
//     char *str = "abracadabra";
//     int n = 10;
//     s21_strncat (des,str,n);
//     strncat (des2,str,n);
//     for (int i = 0; i < 10; i++){
//         printf("%c",des[i]);
//     }
//     putchar('\n');
//         for (int i = 0; i < 10; i++){
//         printf("%c",des2[i]);
//     }
//     putchar('\n');
//     return 0;
// }