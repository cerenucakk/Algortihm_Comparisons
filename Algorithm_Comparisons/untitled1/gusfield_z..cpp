#include "all_algorithms.h"
#include <vector>

std::vector<int> computeZ(const std::string& str) {
    int n = str.length();
    std::vector<int> Z(n);
    int L = 0, R = 0, K;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R] == str[R - L])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            K = i - L;
            if (Z[K] < R - i + 1)
                Z[i] = Z[K];
            else {
                L = i;
                while (R < n && str[R] == str[R - L])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }

    return Z;
}

int algorithms::gusfieldZSearch(const std::string& text, const std::string& pattern) {
    std::string concat = pattern + "$" + text;
    int l = concat.length();

    std::vector<int> Z = computeZ(concat);

    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length())
            return i - pattern.length() - 1; // Pattern found at index i - pattern.length() - 1
    }

    return -1; // Pattern not found
}
