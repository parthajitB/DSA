/**
	https://leetcode.com/problems/palindrome-linked-list/description/
	
	234. Palindrome Linked List
	
	Given the head of a singly linked list, return true if it is a 
	palindrome or false otherwise.
	
	Input: head = [1,2,2,1]
	Output: true
	
	Input: head = [1,2]
	Output: false
	
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
    bool isPalindrome(ListNode* head) {
        
        vector<int> v;

        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }

        int left=0;
        int right=v.size()-1;

        while(left<right && v[left]==v[right])
        {
            left++;
            right--;
        }
        return left>= right;

    }
};

Time: O(N)
space: O(N)

