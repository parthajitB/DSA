/*

	https://leetcode.com/problems/reorder-list/description/?envType=problem-list-v2&envId=e9surc0r
	
	143. Reorder List
	
	You are given the head of a singly linked-list. The list can be represented as:

	L0 → L1 → … → Ln - 1 → Ln
	Reorder the list to be on the following form:

	L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
	You may not modify the values in the list's nodes. Only nodes themselves may be changed.
	
**/

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
    ListNode* middle (ListNode* head)
    {
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }

    ListNode* reverse (ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forwad=nullptr;

        while(curr!=nullptr)
        {
            forwad=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forwad;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next==nullptr)
            return;

        ListNode *mid=middle(head);
        ListNode *lastRev=reverse(mid->next);
        mid->next=nullptr;

        ListNode *c1=head;
        ListNode *c2=lastRev;
        ListNode *f1;
        ListNode *f2;

        while(c1 != nullptr && c2 != nullptr)
        {
            f1=c1->next;
            f2=c2->next;

            c1->next=c2;
            c2->next=f1;

            c1=f1;
            c2=f2;
        }
    }
};

Time: O(N)
space: O(1)

