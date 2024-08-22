#include "all_algorithms.h"

void computeLPSArray(const std::string& pattern, int* lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

int algorithms::kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    int lps[m];
    computeLPSArray(pattern, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]
    while (i < n) {
        if (pattern[j] == text[i]) {
            ++i;
            ++j;
        }
        if (j == m) {
            return i - j; // Pattern found at index i-j
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return -1; // Pattern not found
}
