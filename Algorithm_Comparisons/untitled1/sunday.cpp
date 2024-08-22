#include "all_algorithms.h"

int algorithms::sundaySearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    int shift[256];
    for (int i = 0; i < 256; ++i) {
        shift[i] = m + 1;
    }
    for (int i = 0; i < m; ++i) {
        shift[(unsigned char)pattern[i]] = m - i;
    }

    int i = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m && pattern[j] == text[i + j]) {
            ++j;
        }
        if (j == m) {
            return i; // Pattern found at index i
        } else {
            i += shift[(unsigned char)text[i + m]];
        }
    }

    return -1; // Pattern not found
}
