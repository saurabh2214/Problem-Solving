#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val)
    {
        val=val;
        next=NULL;
    }
};

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return new TreeNode(head->val);
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* mid = NULL;
    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* node = new TreeNode(slow->val);
    mid->next = nullptr;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return node;
}

int main()
{
    ListNode* head=new ListNode(-10);
    head->next=new ListNode(-3);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(5);
    head->next->next->next->next=new ListNode(9);

    TreeNode* root=sortedListToBST(head);
    cout<<root->val;
    return 0;
}