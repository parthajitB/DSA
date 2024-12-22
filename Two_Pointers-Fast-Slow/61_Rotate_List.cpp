/*
	https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=e9surc0r
	
	61. Rotate List

	Given the head of a linked list, rotate the list to the right by k places.
	
	
	Input: head = [1,2,3,4,5], k = 2
	Output: [4,5,1,2,3]
	
	
	Input: head = [0,1,2], k = 4
	Output: [2,0,1]
	
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return head;
        int size = 1;
        ListNode* tmp = head;

        while(tmp->next){
            tmp = tmp->next;
            size++;
        }

        k = size - k % size;
        tmp->next = head;
        while(k--)
            tmp = tmp->next;
            
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};


Time:  O(N)
space: O(1)