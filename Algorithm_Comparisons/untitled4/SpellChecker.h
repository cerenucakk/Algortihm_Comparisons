#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>

// Linear List Approach
class LinearListSpellChecker {
public:
    void buildDictionary(const std::vector<std::string>& words);
    bool checkWord(const std::string& word);

private:
    std::vector<std::string> dictionary;
};

// BBST Approach
class BBSTSpellChecker {
public:
    void buildDictionary(const std::vector<std::string>& words);
    bool checkWord(const std::string& word);

private:
    std::set<std::string> dictionary;
};

// Trie Node
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Trie Approach
class TrieSpellChecker {
public:
    TrieSpellChecker();
    ~TrieSpellChecker();
    void buildDictionary(const std::vector<std::string>& words);
    bool checkWord(const std::string& word);

private:
    TrieNode* root;
    void insert(const std::string& word);
    void deleteTrie(TrieNode* node);  // Helper function for destructor
};

// Hash Map Approach
class HashMapSpellChecker {
public:
    void buildDictionary(const std::vector<std::string>& words);
    bool checkWord(const std::string& word);

private:
    std::unordered_set<std::string> dictionary;
};

// Utility Functions
std::vector<std::string> loadWords(const std::string& filename);

void benchmarkSpellChecker(LinearListSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords);
void benchmarkSpellChecker(BBSTSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords);
void benchmarkSpellChecker(TrieSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords);
void benchmarkSpellChecker(HashMapSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords);

#endif // SPELLCHECKER_H