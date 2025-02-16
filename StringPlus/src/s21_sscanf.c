#include "s21_string.h"

//83.3 52% 
static const char *skip_whitespace(const char *str) {
    while (str && *str && isspace((unsigned char)*str)) {
        str++;
    }
    return str;
}

static const char *parse_integer(const char *str, void *out, int length_modifier, int base, int width, int is_unsigned) {
    if (!str) return s21_NULL;
    char buffer[256] = {0};
    int i = 0;
    const char *start = str;

    while (*str && !isspace((unsigned char)*str) && (width == 0 || i < width)) {
        if (!isxdigit((unsigned char)*str) && (base != 10 || !isdigit((unsigned char)*str))) {
            break;
        }
        buffer[i++] = *str++;
    }
    buffer[i] = '\0';
    if (i == 0) return start;

    char *end_ptr;
    if (is_unsigned) {
        unsigned long long value = strtoull(buffer, &end_ptr, base);
        if (end_ptr == buffer) return start;
        if (length_modifier == 'h') {
            if(out) *(unsigned short *)out = (unsigned short)value;
        } else if (length_modifier == 'l') {
            if(out) *(unsigned long *)out = (unsigned long)value;
        } else if (length_modifier == 'L') {
            if(out) *(unsigned long long *)out = value;
        } else {
            if(out) *(unsigned int *)out = (unsigned int)value;
        }
    } else {
        long long value = strtoll(buffer, &end_ptr, base);
        if (end_ptr == buffer) return start;
        if (length_modifier == 'h') {
            if(out) *(short *)out = (short)value;
        } else if (length_modifier == 'l') {
            if(out) *(long *)out = (long)value;
        } else if (length_modifier == 'L') {
            if(out) *(long long *)out = value;
        } else {
            if(out) *(int *)out = (int)value;
        }
    }

    return str;
}

static const char *parse_float(const char *str, void *out, int length_modifier, int width) {
    if (!str) return s21_NULL;
    char buffer[256] = {0};
    int i = 0;

    while (*str && !isspace((unsigned char)*str) && (width == 0 || i < width)) {
        if (!isdigit((unsigned char)*str) && *str != '.' && *str != 'e' && *str != 'E' && *str != '+' && *str != '-') {
            break;
        }
        buffer[i++] = *str++;
    }
    buffer[i] = '\0';

    if (i == 0) return s21_NULL;

    char *end_ptr;
    long double value = strtold(buffer, &end_ptr);

    if (end_ptr == buffer) return s21_NULL;

    if (length_modifier == 'L') {
        *(long double *)out = value;
    } else {
        *(double *)out = (double)value;
    }
    return str;
}

static const char *parse_char(const char *str, void *out, int width) {
    if (!str || width <= 0) return s21_NULL;
    if(out){
        *(char *)out = *str;
    }
    return str + (width > 0);
}

static const char *parse_string(const char *str, char *out, int width) {
    if (!str) return s21_NULL;
    const char *start = str;
    while (*str && !isspace((unsigned char)*str) && width--) {
        if(out)
            *out++ = *str++;
    }
    if(out)
        *out = '\0';
    return (str == start) ? s21_NULL : str;
}


int s21_sscanf(const char *str, const char *format, ...) {
    if (!str || !format) return 0;
    va_list args;
    va_start(args, format);
    int assigned_count = 0;
    const char *f = format;
    const char *s = str;
    while (*f) {
        if (isspace((unsigned char)*f)) {
            f = skip_whitespace(f);
            s = skip_whitespace(s);
            continue;
        }
        if (*f == '%') {
            f++;
            int length_modifier = 0;
            int width = 0;
            int suppress_assignment = 0;
            while (*f == '*' || isdigit((unsigned char)*f)) {
                if (*f == '*') suppress_assignment = 1;
                if (isdigit((unsigned char)*f)) width = width * 10 + (*f - '0');
                f++;
            }
            if (*f == 'h' || *f == 'l' || *f == 'L') length_modifier = *f++;

            void *arg = suppress_assignment ? s21_NULL : va_arg(args, void *);
            if (!s || !*s) {
                va_end(args);
                return assigned_count;
            }
            switch (*f) {
                case 'd':
                    f++;
                    s = parse_integer(s, arg, length_modifier, 10, width, 0);
                    break;
                case 'i':
                    f++;
                    s = parse_integer(s, arg, length_modifier, 0, width, 0);
                    break;
                case 'u':
                    f++;
                    s = parse_integer(s, arg, length_modifier, 10, width, 1);
                    break;
                case 'o':
                    f++;
                    s = parse_integer(s, arg, length_modifier, 8, width, 1);
                    break;
                case 'x':
                case 'X':
                    f++;
                    s = parse_integer(s, arg, length_modifier, 16, width, 1);
                    break;
                case 'f':
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    f++;
                    s = parse_float(s, arg, length_modifier, width);
                    break;
                case 'c':
                    f++;
                    s = parse_char(s, arg, width ? width : 1);
                    break;
                case 's':
                    f++;
                    s = parse_string(s, arg, width);
                    break;
                case '%':
                    if (*s == '%') {
                        s++;
                    } else {
                        va_end(args);
                        return assigned_count;
                    }
                    f++;
                    break;
                default:
                    va_end(args);
                    return assigned_count;
            }

            if (s) {
                if (!suppress_assignment && s != str) {
                    assigned_count++;
                }
            } else {
                va_end(args);
                return assigned_count;
            }
        } else if (*f == *s) {
            f++;
            s++;
        } else {
            va_end(args);
            return assigned_count;
        }
    }

    va_end(args);
    return assigned_count;
}
