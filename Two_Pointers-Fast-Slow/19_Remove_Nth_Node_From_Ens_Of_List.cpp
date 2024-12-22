/*

	https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=e9surc0r
	
	19. Remove Nth Node From End of List
	
	Given the head of a linked list, remove the nth node from the end of the list and return its head.
	
	Input: head = [1,2,3,4,5], n = 2
	Output: [1,2,3,5]
	Example 2:

	Input: head = [1], n = 1
	Output: []
	
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *slow=head;
        ListNode *fast=head;

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        if(fast==nullptr)
            return head->next;

        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* node=slow->next;
        slow->next=slow->next->next;
        delete node;
        return head;
        
    }
};

Time: O(N)
space: O(1)



