#include <iostream>
#include <vector>
#include <string>
#include "spellchecker.h"

int main() {
    std::vector<std::string> dictionaryWords = loadWords("names.txt");
    std::vector<std::string> textWords = loadWords("message.txt");

    LinearListSpellChecker linearSpellChecker;
    BBSTSpellChecker bbstSpellChecker;
    TrieSpellChecker trieSpellChecker;
    HashMapSpellChecker hashMapSpellChecker;

    benchmarkSpellChecker(linearSpellChecker, dictionaryWords, textWords);
    benchmarkSpellChecker(bbstSpellChecker, dictionaryWords, textWords);
    benchmarkSpellChecker(trieSpellChecker, dictionaryWords, textWords);
    benchmarkSpellChecker(hashMapSpellChecker, dictionaryWords, textWords);

    return 0;
}