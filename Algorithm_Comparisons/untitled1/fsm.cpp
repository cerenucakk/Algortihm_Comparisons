#include "all_algorithms.h"
#include <vector>

std::vector<std::vector<int>> buildFSM(const std::string& pattern) {
    int m = pattern.length();
    std::vector<std::vector<int>> fsm(m + 1, std::vector<int>(256, 0));

    for (int i = 0, lps = 0; i < m; ++i) {
        for (int c = 0; c < 256; ++c) {
            fsm[i][c] = fsm[lps][c];
        }
        fsm[i][pattern[i]] = i + 1;
        if (i > 0) {
            lps = fsm[lps][pattern[i]];
        }
    }

    return fsm;
}

int algorithms::fsmSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    auto fsm = buildFSM(pattern);

    int state = 0;
    for (int i = 0; i < n; ++i) {
        state = fsm[state][text[i]];
        if (state == m) {
            return i - m + 1; // Pattern found at index i-m+1
        }
    }

    return -1; // Pattern not found
}
