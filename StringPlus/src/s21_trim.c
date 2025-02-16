#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    if (!src || !trim_chars) return s21_NULL;

    s21_size_t start = 0, end = s21_strlen(src);
    while (start < end && s21_strchr(trim_chars, src[start])) start++;
    while (end > start && s21_strchr(trim_chars, src[end - 1])) end--;

    char *result = (char *)malloc(end - start + 1);
    if (!result) return s21_NULL;

    for (s21_size_t i = start; i < end; i++) {
        result[i - start] = src[i];
    }
    result[end - start] = '\0';
    return result;
}
