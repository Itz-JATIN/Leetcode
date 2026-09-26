/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void Add(ListNode*& ans, ListNode*& l1, ListNode*& l2, int carry) {

        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            ans = nullptr;
            return;
        }

        int num = carry;

        if (l1 != nullptr) {
            num += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            num += l2->val;
            l2 = l2->next;
        }

        ans = new ListNode(num % 10);

        carry = num / 10;

        Add(ans->next, l1, l2, carry);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = nullptr;

        Add(ans, l1, l2, 0);

        return ans;
    }
};