/*
Sort a linked list in O(n log n) time using constant space complexity.
Subscribe to see which companies asked this question.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if((!head)||(!head->next)) {
            return head;
        }
        ListNode *la,*la_end,*lb,*lb_end;
        ListNode *lit = head;
        ListNode tmp_node(0);
        tmp_node.next = head;
        ListNode *tmp_head = &tmp_node;
        int sorted_size = 1;
        int lsize = 0;
        while(lit) {
            lsize++;
            lit = lit->next;
        }

        while(sorted_size < lsize) {
            lit = tmp_head->next;
            while(lit != nullptr) {
                la = lit;
                lb = move_to(la, sorted_size);
                la_end = lb;
                lb_end = move_to(lb, sorted_size);
                //merge 
                while((la != la_end)&&(lb != lb_end)) {
                    if(la->val > lb->val) {
                        tmp_head->next = lb;
                        tmp_head = tmp_head->next;
                        lb = lb->next;
                    }else {
                        tmp_head->next = la;
                        tmp_head = tmp_head->next;
                        la = la->next;
                    }
                }
                if(la == la_end) {
                    tmp_head->next = lb;
                    while(lb->next != lb_end) {
                        lb = lb->next;
                    }
                    tmp_head = lb;
                }else {
                    tmp_head->next = la;
                    while(la->next != la_end) {
                        la = la->next;
                    }
                    tmp_head = la;
                    la->next = lb_end;
                }
                lit = lb_end;
            }
            sorted_size <<= 1;
            tmp_head = &tmp_node;
        }

        return tmp_head->next;
    }
private:
    ListNode *move_to(ListNode *start, int steps) {
        ListNode *ret = start;
        while((steps > 0)&&(ret)) {
            ret = ret->next;
            steps--;
        }
        return ret;
    }
};

int main() {
    Solution slt;
    const int val_len = 9;
    int val[val_len] = {5,3,2,7,9,6,5,1,8};
    ListNode *Nodes[val_len];
    ListNode *ret;
    for(int i = 0; i < val_len; i++) {
        Nodes[i] = new ListNode(val[i]);
    }
    for(int i = 0; i < val_len - 1; i++) {
        Nodes[i]->next = Nodes[i+1];
    }
    Nodes[val_len - 1]->next = nullptr;
    ListNode *p = Nodes[0];
    while(p) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    
    ret = slt.sortList(Nodes[0]);
    
    p = ret;
    while(p) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}