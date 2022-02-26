#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        } 
        ListNode* dummy = head;
        int count = 0;

        while(dummy != NULL) {
            count++;
            dummy = dummy->next;
        }

        // Checking if k is not greater than List size.
        if(k >= count) {
            k = k%count;
        }
        ListNode *slow = head, *fast = head, *preSlow = head;

        while(k--) {
            fast = fast->next;
        }

        while(fast != NULL && fast->next != NULL) {
            
            slow = slow->next;
            fast = fast->next;
            preSlow = slow;
        }
        
        fast->next = head;
        preSlow = slow->next;
        slow->next = NULL;
        return preSlow;

        }
