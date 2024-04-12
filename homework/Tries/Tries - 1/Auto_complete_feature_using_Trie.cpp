#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
void insert(struct TrieNode* root, const string key)
{
    struct TrieNode* pCrawl = root;
 
    for (int level = 0; level < key.length(); level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isWordEnd = true;
}
 
bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}
 
void suggestionsRec(struct TrieNode* root,
                    string currPrefix)
{
    if (root->isWordEnd)
        cout << currPrefix << endl;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            suggestionsRec(root->children[i],
                           currPrefix + child);
        }
}
int printAutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode* pCrawl = root;
    for (char c : query) {
        int ind = CHAR_TO_INDEX(c);
        if (!pCrawl->children[ind])
            return 0;
 
        pCrawl = pCrawl->children[ind];
    }
    if (isLastNode(pCrawl)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(pCrawl, query);
    return 1;
}