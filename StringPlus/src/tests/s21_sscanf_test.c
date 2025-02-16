#include "s21_string_tests.h"

START_TEST(s21_sscanf_test_EOF1) {
    char fstr[] = "%d";
    char str[] = "        ";
    int16_t res1 = s21_sscanf(str, fstr, 100);
    int16_t res2 = sscanf(str, fstr, 100);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_EOF2) {
    char fstr[] = "%d ";
    char str[] = "               ";
    int16_t a1 = 0, a2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_only_chars1) {
    char fstr[] = "%c %c %c %c";
    char str[] = "   a     b c d";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_only_chars2) {
    char fstr[] = "%c%c%c%c";
    char str[] = "abcd";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_special_symbols_as_chars1) {
    char fstr[] = "%c%c%c%c";
    char str[] = "\\\n\t\t\t";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_special_symbols_as_chars2) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z ' ' /";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_chars_flags1) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_chars_flags2) {
    char fstr[] = "%1c %c %c %0c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_chars_flags3) {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcde";
    int16_t a1 = 0, a2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_chars_aster1) {
    char fstr[] = "%*c%*c%*c%*c";
    char str[] = "   c ";
    int16_t a1 = 0, a2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_chars_aster2) {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcd ";
    int16_t a1 = 0, a2 = 0;
    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_only_ints1) {
    long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char fstr[] = "%ld %ld %ld %ld";
    const char str[] = "555 666 777 888";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_only_ints2) {
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 3000";
    const char fstr[] = "%hd %hd %hd %hd";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_ints_nwidth1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 300004";
    const char fstr[] = "%1lld %3lld %1lld %4lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_ints_nwidth2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%1lld %1lld %1lld %1lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_ints_astwidth1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    const char str[] = "1337123123 1 123412341234 1 999999 0";
    const char fstr[] = "%*d %lld %*d %lld %*d %lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(s21_sscanf_test_ints_astwidth2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_signed_ints1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "11337 ++3 -5 ------4";
    const char fstr[] = "%lld %lld %lld %lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_signed_ints2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "-1337 +1 -1 -1";
    const char fstr[] = "%15lld %1lld %1lld %5lld";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_int1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300 500 -600 +700";
    const char fstr[] = "%lli %lli %lli %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_int2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300500-600+700 111";
    const char fstr[] = "%lli %lld %lld %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_hex1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "0xFFF 0xA123123 0x123123 0x0";
    const char fstr[] = "%lli %lld %lld %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_hex2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_oct1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_spec_i_oct2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_strings1) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};
    const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
    const char fstr[] = "%s %s %s %s";
    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(s21_sscanf_test_strings_mixed3) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
    const char fstr[] = "%s%ld%s%d%s%d%s";
    int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
    int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(s21_sscanf_test_strings2) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};
    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%s%s%s%s";
    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(s21_sscanf_test_strings_mixed1) {
    int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
    long long v1, v2;
    const char str[] = "1 1 1 1 1 -1";
    const char fstr[] = "%1s %5d %1s %1s %d %lld %d";
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
    int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(s1, s2);
    ck_assert_str_eq(s3, s4);
    ck_assert_str_eq(s5, s6);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_n1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int32_t n1 = 0, n2 = 5;
    const char str[BUFF_SIZE] = "50 160 70 80";
    const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_n2) {
    int n1 = 1, n2 = 5;
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
    const char fstr[] = "%s %s %n %s";
    int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
    int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(s21_sscanf_test_floats1) {
    long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;
    const char str[] = "53.1 -4.1135 41.3333 +2.0001";
    const char fstr[] = "%Lf %Lf %Lf %Lf";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_floats2) {
    double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "0.00001 -4123123 4. .";
    const char fstr[] = "%lf %lf %lf %lf";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_floats_sci1) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
    const char fstr[] = "%G %G %G %G";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_floats_sci2) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "inf 1.31e+4 NaN 0.444e-5";
    const char fstr[] = "%G %G %G %G";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_ldouble_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_float_nan(c1);
    ck_assert_float_nan(c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_uint1) {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_uint_eq(res1, res2);
    ck_assert_uint_eq(a1, a2);
    ck_assert_uint_eq(b1, b2);
    ck_assert_uint_eq(c1, c2);
    ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_uint2) {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0,
                           d1 = 0, d2 = 0;
    const char str[] = "-1337 233333331 5008 3000";
    const char fstr[] = "%1llu %2llu %5llu %4llu";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_base_version) {
    uint32_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_overflow) {
    uint32_t a1, a2;
    const char str[] = "0xFFFFFFFF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_0X) {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_fail) {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_short) {
    uint16_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%hX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_long) {
    unsigned long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%lX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_longlong) {
    unsigned long long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%llX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_2x) {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_star) {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*X";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_lower) {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upeer_hex_sign) {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_base_version) {
    uint32_t a1, a2;
    const char str[] = "f";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_overflow) {
    uint32_t a1, a2;
    const char str[] = "0xfffffffffffffffffff";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_0X) {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_fail) {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_short) {
    uint16_t a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%hx";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_long) {
    unsigned long int a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%lx";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_2x) {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_star) {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*x";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_lower) {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_sign) {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_upper_hex_len) {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_lower_hex_len) {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_base_version) {
    uint32_t a1, a2;
    const char str[] = "777";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_overflow) {
    uint32_t a1, a2;
    const char str[] = "0x7777777777777777777777";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     5";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_short) {
    uint16_t a1, a2;
    const char str[] = "12";
    const char fstr[] = "%ho";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_long) {
    unsigned long int a1, a2;
    const char str[] = "57234";
    const char fstr[] = "%lo";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_2x) {
    uint32_t a1, a2;
    const char str[] = "0x12320x213x123213";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_star) {
    const char str[] = "521561612";
    const char fstr[] = "%*o";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_lower) {
    uint32_t a1, a2;
    const char str[] = "01234567";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_sign) {
    uint32_t a1, a2;
    const char str[] = "-66";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_octal_len) {
    uint32_t a1, a2;
    const char str[] = "123531";
    const char fstr[] = "%2o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_buff1) {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12 keppa 12";
    const char fstr[] = "%d keppa %d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(s21_sscanf_test_buff2) {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12keppa12";
    const char fstr[] = "%dkeppa%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(s21_sscanf_test_pointer1) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_pointer2) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";
    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_perc1) {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12 % 13 % 14";
    const char fstr[] = "%d %% %d %% %d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(s21_sscanf_test_perc2) {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12%13%14";
    const char fstr[] = "%d%%%d%%%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(s21_sscanf_test_mixed_ptrs1) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAA 7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_mixed_ptrs2) {
    char *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0x4 0x3 0x2 0x1";
    const char fstr[] = "%p %p %p %p";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

Suite *suite_s21_sscanf() {
    Suite *suite = suite_create("s21_sscanf");
    TCase *normal_tests = tcase_create("s21_sscanf_test");
    tcase_add_test(normal_tests, s21_sscanf_test_EOF1);
    tcase_add_test(normal_tests, s21_sscanf_test_EOF2);
    tcase_add_test(normal_tests, s21_sscanf_test_only_chars1);
    tcase_add_test(normal_tests, s21_sscanf_test_only_chars2);
    tcase_add_test(normal_tests, s21_sscanf_test_special_symbols_as_chars1);
    tcase_add_test(normal_tests, s21_sscanf_test_special_symbols_as_chars2);
    tcase_add_test(normal_tests, s21_sscanf_test_chars_flags1);
    tcase_add_test(normal_tests, s21_sscanf_test_chars_flags2);
    tcase_add_test(normal_tests, s21_sscanf_test_chars_flags3);
    tcase_add_test(normal_tests, s21_sscanf_test_chars_aster1);
    tcase_add_test(normal_tests, s21_sscanf_test_chars_aster2);
    tcase_add_test(normal_tests, s21_sscanf_test_only_ints1);
    tcase_add_test(normal_tests, s21_sscanf_test_only_ints2);
    tcase_add_test(normal_tests, s21_sscanf_test_ints_nwidth1);
    tcase_add_test(normal_tests, s21_sscanf_test_ints_nwidth2);
    tcase_add_test(normal_tests, s21_sscanf_test_ints_astwidth1);
    tcase_add_test(normal_tests, s21_sscanf_test_ints_astwidth2);
    tcase_add_test(normal_tests, s21_sscanf_test_signed_ints1);
    tcase_add_test(normal_tests, s21_sscanf_test_signed_ints2);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_int1);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_int2);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_oct1);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_oct2);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_hex1);
    tcase_add_test(normal_tests, s21_sscanf_test_spec_i_hex2);
    tcase_add_test(normal_tests, s21_sscanf_test_strings1);
    tcase_add_test(normal_tests, s21_sscanf_test_strings2);
    tcase_add_test(normal_tests, s21_sscanf_test_uint1);
    tcase_add_test(normal_tests, s21_sscanf_test_uint2);
    tcase_add_test(normal_tests, s21_sscanf_test_strings_mixed1);
    tcase_add_test(normal_tests, s21_sscanf_test_strings_mixed3);
    tcase_add_test(normal_tests, s21_sscanf_test_floats1);
    tcase_add_test(normal_tests, s21_sscanf_test_floats2);
    tcase_add_test(normal_tests, s21_sscanf_test_floats_sci1);
    tcase_add_test(normal_tests, s21_sscanf_test_floats_sci2);
    tcase_add_test(normal_tests, s21_sscanf_test_n1);
    tcase_add_test(normal_tests, s21_sscanf_test_n2);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_base_version);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_overflow);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_0x);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_0X);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_empty);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_fail);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_spaces_tabs_sns);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_short);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_long);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_longlong);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_2x);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_star);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_nohex);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_lower);
    tcase_add_test(normal_tests, s21_sscanf_test_upeer_hex_sign);
    tcase_add_test(normal_tests, s21_sscanf_test_upper_hex_len);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_base_version);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_overflow);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_0x);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_0X);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_empty);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_fail);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_spaces_tabs_sns);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_short);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_long);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_2x);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_star);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_nohex);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_lower);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_sign);
    tcase_add_test(normal_tests, s21_sscanf_test_lower_hex_len);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_base_version);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_overflow);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_0x);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_empty);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_spaces_tabs_sns);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_short);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_long);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_2x);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_star);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_nohex);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_lower);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_sign);
    tcase_add_test(normal_tests, s21_sscanf_test_octal_len);
    tcase_add_test(normal_tests, s21_sscanf_test_pointer1);
    tcase_add_test(normal_tests, s21_sscanf_test_pointer2);
    tcase_add_test(normal_tests, s21_sscanf_test_buff1);
    tcase_add_test(normal_tests, s21_sscanf_test_buff2);
    tcase_add_test(normal_tests, s21_sscanf_test_perc1);
    tcase_add_test(normal_tests, s21_sscanf_test_perc2);
    tcase_add_test(normal_tests, s21_sscanf_test_mixed_ptrs1);
    tcase_add_test(normal_tests, s21_sscanf_test_mixed_ptrs2);
    suite_add_tcase(suite, normal_tests);
    return suite;
}