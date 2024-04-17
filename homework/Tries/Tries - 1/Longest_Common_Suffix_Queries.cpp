#include<bits/stdc++.h>
using namespace std;

struct TriesNode{
        int LessLengthIndex=0;
        TriesNode* children[26];
        TriesNode(int index)
        {
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
            LessLengthIndex=index;
        }
};
void insert(TriesNode*root,int i,vector<string>& wordsContainer)
{
    TriesNode* curr=root;
    if(wordsContainer[i].length() < wordsContainer[curr -> LessLengthIndex].length())
        curr -> LessLengthIndex = i;
    for(int j = wordsContainer[i].length() - 1; j >= 0; j--) {
        int ch = (wordsContainer[i][j] - 'a');
        if(curr -> children[ch] == NULL) {
            curr -> children[ch] = new TriesNode(i);
        } 
        curr = curr -> children[ch];
        if(wordsContainer[i].length() < wordsContainer[curr -> LessLengthIndex].length()) 
            curr -> LessLengthIndex = i;
    }
}
int search(TriesNode *root, string word) {
    TriesNode* curr = root;
    for(int i = word.size() - 1; i >= 0; i--) {
        int ch = word[i] - 'a';
        if(curr -> children[ch] == NULL) {
            return curr -> LessLengthIndex;
        } 
        curr = curr -> children[ch];
    }
    return curr -> LessLengthIndex;
}
vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    TriesNode *root = new TriesNode(0);
    for(int i = 0; i < wordsContainer.size(); i++) {
        insert(root, i, wordsContainer);
    }
    vector<int> ans;
    for(int i = 0; i < wordsQuery.size(); i++) {
        ans.push_back(search(root, wordsQuery[i]));
    }
    return ans;
}