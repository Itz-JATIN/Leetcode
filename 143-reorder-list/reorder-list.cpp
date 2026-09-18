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

    void Add(ListNode*& result, ListNode*& tail, int value) {

        ListNode* newNode = new ListNode(value);

        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reorderList(ListNode* head) {

        ListNode* temp = head;
        vector<int> ans;

        while (temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* result = nullptr;
        ListNode* tail = nullptr;

        int first = 0;
        int second = ans.size() - 1;
        int k = 0;

        while (first <= second) {

            if (k % 2 == 0) {
                Add(result, tail, ans[first]);
                first++;
            }
            else {
                Add(result, tail, ans[second]);
                second--;
            }

            k++;
        }

        // Copy reordered values back into original list
        temp = head;
        ListNode* newTemp = result;

        while (temp != nullptr) {
            temp->val = newTemp->val;
            temp = temp->next;
            newTemp = newTemp->next;
        }
    }
};