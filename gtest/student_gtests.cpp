#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup) {
	char *str1 = String::strdup("foo");
	EXPECT_STREQ(str1, "foo");
	delete[] str1;

	char *str2 = String::strdup("");
	EXPECT_STREQ(str2, "");
	delete[] str2;
}

TEST(StringFunction, strncpy) {
    char result1[10];
    EXPECT_EQ(String::strncpy(result1, "foo", 9), result1);
    EXPECT_STREQ(result1, "foo");

    char result2[10];
    EXPECT_EQ(String::strncpy(result2, "foofoo", 3), result2);
    EXPECT_STREQ(result2, "foo");

    char result3[10];
    EXPECT_EQ(String::strncpy(result3, "", 9), result3);
    EXPECT_STREQ(result3, "");

    char result4[10];
    EXPECT_EQ(String::strncpy(result4, "foo", 0), result4);
    EXPECT_STREQ(result4, "");
}

TEST(StringFunction, strcat) {
    char result1[10]{"abc"};
    EXPECT_EQ(String::strcat(result1, "def"), result1);
    EXPECT_STREQ(result1, "abcdef");

    char result2[10]{"abc"};
    EXPECT_EQ(String::strcat(result2, ""), result2);
    EXPECT_STREQ(result2, "abc");

    char result3[10]{""};
    EXPECT_EQ(String::strcat(result3, "xyz"), result3);
    EXPECT_STREQ(result3, "xyz");
}

TEST(StringFunction, strncat) {
    char result1[10]{"abc"};
    EXPECT_EQ(String::strncat(result1, "def", 4), result1);
    EXPECT_STREQ(result1, "abcdef");

    char result2[10]{"abc"};
    EXPECT_EQ(String::strncat(result2, "def", 1), result2);
    EXPECT_STREQ(result2, "abcd");

    char result3[10]{"abc"};
    EXPECT_EQ(String::strncat(result3, "def", 0), result3);
    EXPECT_STREQ(result3, "abc");

    char result4[10]{""};
    EXPECT_EQ(String::strncat(result4, "def", 1), result4);
    EXPECT_STREQ(result4, "d");
}

TEST(StringFunction, strcmp) {
   EXPECT_EQ(String::strcmp("abc", "abc"), 0);
   EXPECT_LT(String::strcmp("abc", "abd"), 0);
   EXPECT_GT(String::strcmp("abc", "abb"), 0);
   EXPECT_LT(String::strcmp("abc", "abcd"), 0);
   EXPECT_GT(String::strcmp("abc", "ab"), 0);
   EXPECT_EQ(String::strcmp("", ""), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abc", 4), 0);
    EXPECT_EQ(String::strncmp("abc", "abd", 2), 0);
    EXPECT_EQ(String::strncmp("abc", "aba", 3), 2);
    EXPECT_EQ(String::strncmp("abc", "abd", 3), -1);
    EXPECT_EQ(String::strncmp("", "", 1), 0);
}

TEST(StringFunction, reverse_cpy) {
    char d1[10]{};
    const char s1[]{"word"};
    const char expected1[]{"drow"};
    String::reverse_cpy(d1, s1);
    EXPECT_STREQ(d1, expected1);

    char d2[10]{};
    const char s2[]{""};
    const char expected2[]{""};
    String::reverse_cpy(d2, s2);
    EXPECT_STREQ(d2, expected2);
}

TEST(StringFunction, strchr) {
    const char str1[]{"coconut"};
    const char *res_ptr1 = &(str1[1]);
    EXPECT_EQ(String::strchr(str1, 'o'), res_ptr1);

    const char str2[]{"coconut"};
    const char *res_ptr2 = &(str2[7]);
    EXPECT_EQ(String::strchr(str2, '\0'), res_ptr2);

    const char str3[]{"coconut"};
    const char *res_ptr3 = nullptr;
    EXPECT_EQ(String::strchr(str3, 'a'), res_ptr3);
}

TEST(StringFunction, strstr) {
    const char h1[]{"coconut"};
    const char n1[]{"con"};
    const char *res_ptr1 = &(h1[2]);
    EXPECT_EQ(String::strstr(h1, n1), res_ptr1);

    const char h2[]{"coconut"};
    const char n2[]{"dino"};
    const char *res_ptr2 = nullptr;
    EXPECT_EQ(String::strstr(h2, n2), res_ptr2);

    const char h3[]{"coconut"};
    const char n3[]{""};
    const char *res_ptr3 = &(h3[0]);
    EXPECT_EQ(String::strstr(h3, n3), res_ptr3);

    const char h4[]{""};
    const char n4[]{"apple"};
    const char *res_ptr4 = nullptr;
    EXPECT_EQ(String::strstr(h4, n4), res_ptr4);
}
