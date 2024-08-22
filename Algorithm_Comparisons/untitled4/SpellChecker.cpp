#include "spellchecker.h" // Include the header file where the spell checker classes are defined
#include <algorithm> // Include algorithm for std::find
#include <fstream> // Include fstream for file operations
#include <chrono> // Include chrono for measuring time
#include <iostream> // Include iostream for console output
yhy
// Linear List Approach
// Class for spell checker using a linear list (vector) to store dictionary words
void LinearListSpellChecker::buildDictionary(const std::vector<std::string>& words) {
    dictionary = words; // Store the given words in the dictionary
}

bool LinearListSpellChecker::checkWord(const std::string& word) {
    // Check if the word exists in the dictionary using std::find
    return std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

// BBST Approach
// Class for spell checker using a Balanced Binary Search Tree (BBST) to store dictionary words
void BBSTSpellChecker::buildDictionary(const std::vector<std::string>& words) {
    for (const auto& word : words) {
        dictionary.insert(word); // Insert each word into the set (BBST)
    }
}

bool BBSTSpellChecker::checkWord(const std::string& word) {
    // Check if the word exists in the dictionary using the set's find method
    return dictionary.find(word) != dictionary.end();
}

// Trie Approach
// Class for spell checker using a Trie data structure to store dictionary words
TrieSpellChecker::TrieSpellChecker() {
    root = new TrieNode(); // Initialize the root node
}

TrieSpellChecker::~TrieSpellChecker() {
    deleteTrie(root); // Delete the Trie when the object is destroyed
}

void TrieSpellChecker::deleteTrie(TrieNode* node) {
    for (auto& pair : node->children) {
        deleteTrie(pair.second); // Recursively delete all children nodes
    }
    delete node; // Delete the current node
}

void TrieSpellChecker::buildDictionary(const std::vector<std::string>& words) {
    for (const auto& word : words) {
        insert(word); // Insert each word into the Trie
    }
}

bool TrieSpellChecker::checkWord(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            return false; // If the character is not found, the word is not in the dictionary
        }
        node = node->children[c]; // Move to the next node
    }
    return node->isEndOfWord; // Check if the last node marks the end of a word
}

void TrieSpellChecker::insert(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode(); // Create a new node if it doesn't exist
        }
        node = node->children[c]; // Move to the next node
    }
    node->isEndOfWord = true; // Mark the end of the word
}

// Hash Map Approach
// Class for spell checker using a hash map (unordered_set) to store dictionary words
void HashMapSpellChecker::buildDictionary(const std::vector<std::string>& words) {
    for (const auto& word : words) {
        dictionary.insert(word); // Insert each word into the hash map
    }
}

bool HashMapSpellChecker::checkWord(const std::string& word) {
    // Check if the word exists in the dictionary using the hash map's find method
    return dictionary.find(word) != dictionary.end();
}

// Utility Functions
// Function to load words from a file into a vector of strings
std::vector<std::string> loadWords(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    std::vector<std::string> words;
    std::string word;
    while (file >> word) { // Read each word from the file
        words.push_back(word); // Add the word to the vector
    }
    return words; // Return the vector of words
}

// Benchmarking Functions
// Function to benchmark the Linear List Spell Checker
void benchmarkSpellChecker(LinearListSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords) {
    auto start = std::chrono::high_resolution_clock::now();
    spellChecker.buildDictionary(dictionaryWords); // Measure time to build the dictionary
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> buildTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (const auto& word : textWords) {
        spellChecker.checkWord(word); // Measure time to check each word in the text
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> checkTime = end - start;

    std::cout << "Linear List: Build Time = " << buildTime.count() << "s, Check Time = " << checkTime.count() << "s" << std::endl;
}

// Function to benchmark the BBST Spell Checker
void benchmarkSpellChecker(BBSTSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords) {
    auto start = std::chrono::high_resolution_clock::now();
    spellChecker.buildDictionary(dictionaryWords); // Measure time to build the dictionary
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> buildTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (const auto& word : textWords) {
        spellChecker.checkWord(word); // Measure time to check each word in the text
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> checkTime = end - start;

    std::cout << "BBST: Build Time = " << buildTime.count() << "s, Check Time = " << checkTime.count() << "s" << std::endl;
}

// Function to benchmark the Trie Spell Checker
void benchmarkSpellChecker(TrieSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords) {
    auto start = std::chrono::high_resolution_clock::now();
    spellChecker.buildDictionary(dictionaryWords); // Measure time to build the dictionary
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> buildTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (const auto& word : textWords) {
        spellChecker.checkWord(word); // Measure time to check each word in the text
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> checkTime = end - start;

    std::cout << "Trie: Build Time = " << buildTime.count() << "s, Check Time = " << checkTime.count() << "s" << std::endl;
}

// Function to benchmark the Hash Map Spell Checker
void benchmarkSpellChecker(HashMapSpellChecker& spellChecker, const std::vector<std::string>& dictionaryWords, const std::vector<std::string>& textWords) {
    auto start = std::chrono::high_resolution_clock::now();
    spellChecker.buildDictionary(dictionaryWords); // Measure time to build the dictionary
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> buildTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (const auto& word : textWords) {
        spellChecker.checkWord(word); // Measure time to check each word in the text
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> checkTime = end - start;

    std::cout << "Hash Map: Build Time = " << buildTime.count() << "s, Check Time = " << checkTime.count() << "s" << std::endl;
}
