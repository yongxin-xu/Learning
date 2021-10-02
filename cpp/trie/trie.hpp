#include <iostream>
#include <unordered_map>
#include <string>

namespace {
struct TrieNode {
    std::unordered_map<char, TrieNode *> children;
    bool terminate;

    TrieNode(): terminate(false) {}
};
}

class Trie {
public:
    Trie() :root(new TrieNode()) {}
    
    void insert(std::string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                TrieNode *tnode = new TrieNode();
                curr->children[ch] = tnode;
            } 
            curr = curr->children[ch];
        }
        curr->terminate = true;
    }
    
    bool search(std::string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->terminate;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode *curr = root;
        for (char ch : prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }

private:
    TrieNode *root;
};