#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[2];
    long long count;
};

void insert(int pre_xor, TrieNode* root) {
    TrieNode* temp = root;
    for (int i=31; i>=0; i--) {
        bool val = pre_xor & (1<<i);
        if (temp->children[val] == NULL)
            temp->children[val] = new TrieNode();
        temp = temp->children[val];
        temp->count++;
    }
}

long long lessThanK(int pre_xor, TrieNode* root, int k) {
    TrieNode* temp = root;
    long long res = 0;
    for (int i=31; i>=0; i--) {
        bool val = pre_xor & (1<<i);
        bool kval = k & (1<<i);
        if (kval == 0) {
            if (temp->children[val] != NULL) {
                temp = temp->children[val];
            } else {
                break;
            }
        } else {
            if (temp->children[val] != NULL) {
                res += temp->children[val]->count;
            }
            if (temp->children[1-val] != NULL) {
                temp = temp->children[1-val];
            } else {
                break;
            }
        }
    }
    return res;
}

long long subarrayXorLessK(vector<int> arr, int n, int k) {
    TrieNode* root = new TrieNode();
    insert(0, root);
    long long res = 0, pre_xor =0;
    for (int i=0; i<n; i++) {
        pre_xor = pre_xor^arr[i];
        res += lessThanK(pre_xor, root, k);
        insert(pre_xor, root);
    }
    return res;
}

int main() {
	int num;
	cin >> num;    
	for(int i=0;i<num;i++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			arr.push_back(a);
		}
		cout << subarrayXorLessK(arr, n, k) << endl;
	}
}