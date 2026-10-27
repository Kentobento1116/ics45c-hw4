// Returns length of string before null terminating character
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
