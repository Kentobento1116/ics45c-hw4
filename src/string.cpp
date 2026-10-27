#include <iostream>

#include "string.hpp"

using namespace std;

// Constructs a String from a C string
String::String(const char *s) {
    strdup(s);
}

// Constructs a String as a copy of String s
String::String(const String &s) {
    strdup(s.buf);
}

// Swap buf between string and s using std::swap
void String::swap(String &s) {

}

// Assign String s to this String
String &String::operator=(const String &s) {
    if (this == &s)
        return *this;

    strcpy(buf, s.buf);
    return *this;
}

// Allow indexing this string with s[i]
char &String::operator[](int index) {
    if (index < 0 || index >= strlen(buf)) {
        cout << "ERROR: Index Out Of Bounds";
        return buf[0];
    }
    return buf[index];
}

// Returns logical length of this String
int String::size() const {
    return strlen(buf);
}

// Returns reverse of this String
// Does not modify this String
String String::reverse() const {
    String temp;
    reverse_cpy(temp.buf, buf);
    return temp;
}

// Returns index of first occurence of c
int String::indexOf(char c) const {
    const char *p = strchr(buf, c);
    if (p != nullptr)
        return p - buf; // Pointer arithmetic
    return -1;
}

// Returns index of first occurrence of s
int String::indexOf(const String &s) const {
    if (strlen(s.buf) == 0)
        return 0;

    const char *p = strstr(buf, s.buf);
    if (p != nullptr)
        return p - buf; // Pointer arithmetic
    return -1;
}

bool String::operator==(const String &s) const {
    if (strcmp(buf, s.buf) == 0)
        return true;
    return false;
}

bool String::operator!=(const String &s) const {
    if (strcmp(buf, s.buf) != 0)
        return true;
    return false;
}

bool String::operator>(const String &s) const {
    if (strcmp(buf, s.buf) > 0)
        return true;
    return false;
}

bool String::operator<(const String &s) const {
    if (strcmp(buf, s.buf) < 0)
        return true;
    return false;
}

bool String::operator<=(const String &s) const {
    if (strcmp(buf, s.buf) <= 0)
        return true;
    return false;
}

bool String::operator>=(const String &s) const {
    if (strcmp(buf, s.buf) >= 0)
        return true;
    return false;
}

// Concatenate this and s and return String
String String::operator+(const String &s) const {
    String R;
    strcpy(R.buf, buf);
    int remaining_space = MAXLEN - strlen(buf) - 1;

    if (strlen(s.buf) > remaining_space) {
        cout << "ERROR: String Capacity Exceeded";
        strncat(R.buf, s.buf, remaining_space);
    }
    else
        strcat(R.buf, s.buf);
    return R;
}

// Concatenate s onto end of this String
String &String::operator+=(const String &s) {
    char temp[MAXLEN];
    strcpy(temp, s.buf);

    int remaining_space = MAXLEN - strlen(buf) - 1;

    if (strlen(s.buf) > remaining_space) {
        cout << "ERROR: String Capacity Exceeded";

        if (remaining_space > 0)
            strncat(buf, temp, remaining_space);
    }
    else
        strcat(buf, temp);
    return *this;
}

// Print this String
void String::print(std::ostream &out) const {
    out << buf;
}

// Read next word into this String
void String::read(std::istream &in) {
    char content[MAXLEN];

    if (in >> content)
        strcpy(buf, content);
}

// Destructor
String::~String() {

}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}

// Returns reverse of this String// Returns length of string before null terminating character
int String::strlen(const char *s) {
    int i = 0;
    for ( ; s[i] != '\0'; ++i) {}
    return i;
}

// Copies src into dest, including null terminating character
char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    for ( ; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

// Takes C string and returns a duplicate with its own heap storage
char *String::strdup(const char *src) {
	int len = strlen(src);
	char *dup = new char[len + 1];
	strcpy(dup, src);
	return dup;
}

// dest and src point to first char in char array
// Copies first n amount of characters from src to dest
char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

// Appends copy of src to dest
// dest null terminating character overwritten by first
// char of src
char *String::strcat(char *dest, const char *src) {
    int i = 0;
    for ( ; dest[i] != '\0'; ++i) {}
    for (int j = 0; src[j] != '\0'; ++j) {
        dest[i] = src[j];
        ++i;
    }

// Appends first n characters from src onto dest
char *String::strncat(char *dest, const char *src, int n) {
    int i = 0;
    for ( ; dest[i] != '\0'; ++i) {}
    for (int j = 0; src[j] != '\0' && j < n; ++j) {
        dest[i] = src[j];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

// Compares two C strings
// Compares one character at a time until they differ or reach
// null terminating character
// <0 - first char to not match has a lower value in left than right
// 0 - contents are equal
// >0 - first char to not match has a greater value in left than right
int String::strcmp(const char *left, const char *right) {
    int i = 0;
    for ( ; left[i] == right[i] && left[i] != '\0'; ++i) {}

    return static_cast<unsigned char>(left[i]) - static_cast<unsigned char>(right[i]);
}

// Compares up to n characters
int String::strncmp(const char *left, const char *right, int n) {
    if (n == 0)
        return 0;
    int i = 0;
    for ( ; left[i] == right[i] && left[i] != '\0' && i < n-1; ++i) {}

    return static_cast<unsigned char>(left[i]) - static_cast<unsigned char>(right[i]);
}

// Moves the reverse of src into dest
void String::reverse_cpy(char *dest, const char *src) {
    int len = strlen(src);

    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

// Locate first occurrence of c in str
// Return pointer to first occurence
// Return nullptr if not found
const char *String::strchr(const char *str, char c) {
    int i = 0;
    for ( ; str[i] != c && str[i] != '\0'; ++i) {}

    if (str[i] != c && str[i] == '\0')
        return nullptr;
    return &str[i];
}

// Locate first occurrence of needle in haystack
// Return pointer to first occurrence
// Return nullptr if not found
const char *String::strstr(const char *haystack, const char *needle) {
    if (needle[0] == '\0')
        return haystack;

    int len = strlen(needle);

    for (const char *p = haystack; (p = strchr(p, needle[0])); ++p) {
        if (strncmp(p, needle, len) == 0)
            return p;
    }
    return nullptr;
}
