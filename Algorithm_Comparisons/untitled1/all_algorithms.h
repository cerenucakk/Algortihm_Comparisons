#ifndef ALL_ALGORITHMS_H
#define ALL_ALGORITHMS_H

#include <string>
namespace algorithms{
int bruteForceSearch(const std::string &text, const std::string &pattern);
int sundaySearch(const std::string &text, const std::string &pattern);
int kmpSearch(const std::string &text, const std::string &pattern);
int fsmSearch(const std::string &text, const std::string &pattern);
int rabinKarpSearch(const std::string &text, const std::string &pattern);
int gusfieldZSearch(const std::string &text, const std::string &pattern);
}
#endif
