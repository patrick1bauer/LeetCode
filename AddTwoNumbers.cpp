/**
 * Patrick Bauer
 * Leetcode
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/
 */

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
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // Create a new linked list and a temporary pointer to add new nodes to it.        
        ListNode* answer = new ListNode();
        ListNode* temp = answer;

        int carry = 0;

        // Iterate through given linked lists.
        while (l1 != nullptr || l2 != nullptr || carry >= 1)
        {
            // Get sum of current digits and carry.
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update the carry value.
            carry = sum / 10;
            
            // Create a new node containing the one's place digit and add it to the list.
            temp->next = new ListNode(sum % 10);

            // Move the temporary pointer to point to the newly created node.
            temp = temp->next;

        }
        // Since the first node was created as a placeholder, return a pointer to the next node.
        return answer->next;
    }
};