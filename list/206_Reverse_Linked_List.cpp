
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode ph(0);
        __rotateList(head, &ph);
        return ph.next;
    }
private:
    ListNode* __rotateList(ListNode* root, ListNode* head) {
        if(!root->next) {
            head->next = root;
            return root;
        }
        ListNode* nd = __rotateList(root->next, head);
        root->next = nd->next;
        nd->next = root;
        return root;
    }
};

ListNode *create_list(vector<int> &input) {
    ListNode *node = new ListNode(input[0]);
    ListNode *prev = node;
    ListNode *head = node;
    for(int i = 1; i < input.size(); i++) {
        node = new ListNode(input[i]);
        prev->next = node;
        prev = node;
    }
    return head;
}

void printList(ListNode *head) {
    while(head) {
        cout<<head->val<<", ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    vector<int> x1 = {7,3,2,5,1,8};
    ListNode* head1 = create_list(x1);
    printList(head1);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.reverseList(head1);
    printList(head);
}
