#ifndef S21_STRING
#define S21_STRING

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


#define s21_size_t unsigned long long
#define s21_NULL ((void *)0)
#define S21_MAX_SPEC_SIZE 32

void *s21_memchr (const void* str, int expected, s21_size_t lenght);
int s21_memcmp (const void *str1, const void *str2, s21_size_t len);
void *s21_memcpy (void *dest, const void *src, s21_size_t n);
void *s21_memset (void *str, int ch, s21_size_t n);
char *s21_strchr (const char* str, int ch);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen (const char* str);
char *s21_strncat (char *dest, const char* str, s21_size_t n);
int s21_strncmp (const char* str1, const char* str2, s21_size_t n);
void *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk (const char* str1, const char* str2);
char *s21_strrchr (const char* str, int ch);
char *s21_strstr(const char* str, const char* substr);
char *s21_strtok(char *str, const char *delim);
int s21_sscanf(const char *str, const char *s21_format, ...);
void ctoa(char *str, char ch);
void itoa (char *str,int value);
void ftoa (char *str, float value, s21_size_t tochnost);
void utoa(char *str,unsigned int value);
char *s21_strcat (char *dest, const char* str);
void *s21_strcpy(char *dest, const char *src);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t star_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif