#include "../../s21_string.h"

void *itoa (char *str,int value){
    int i;
    int negativ;
    if (value < 0){
        value = value * (-1);
    }
    while (value != 0){
        str[i] = (value%10) + 48;
        value = value/10;
        i++;   
    }
    str[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--){
        char temp = str [j];
        str[j] = str[k];
        str[k] = str [j];
    }
}