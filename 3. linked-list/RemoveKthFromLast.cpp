#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


  ListNode* removeKthFromEnd(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        } 
        
        ListNode* dummy = head;
        int count = 0;
        while(dummy != NULL) {
            count+=1;
            dummy = dummy->next;
        }
        
        if(k>count) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPre = head;
        while(k--) {
            fast = fast->next;
        }

        while(fast != NULL) {
            slowPre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        //if(slow != NULL){
            slowPre->next = slow->next;
        //}
        //else slowPre->next = slow;
        if(head == slow) {
            head = head->next;
        }
        delete(slow);
        return head;
    }