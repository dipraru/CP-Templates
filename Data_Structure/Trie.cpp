#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

class Node {
public:
    bool isEndOfWord;
    Node* children[ALPHABET_SIZE];

    Node() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;

    void deleteNode(Node* node, std::string key, int depth) {
        if (node == nullptr) {
            return;
        }

        if (depth == key.length()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
            }
            return;
        }

        int index = key[depth] - 'a';
        deleteNode(node->children[index], key, depth + 1);

        if (!node->isEndOfWord) {
            bool isEmpty = true;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (node->children[i] != nullptr) {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty) {
                delete node;
                node = nullptr;
            }
        }
    }

public:
    Trie() {
        root = new Node();
    }

    void insert(std::string key) {
        Node* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(std::string key) {
        Node* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return (current != nullptr && current->isEndOfWord);
    }

    void deleteString(std::string key) {
        deleteNode(root, key, 0);
    }
};
