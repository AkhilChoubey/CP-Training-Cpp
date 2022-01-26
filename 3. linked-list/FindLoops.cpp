#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    bool hasCycle(ListNode *head) {
        
          if (head == NULL || head->next == NULL) {
        return false;
    }
    else {
    ListNode *slow = head->next, *fast = head->next->next;

    while(slow != NULL && fast !=NULL){

        if(slow == fast) {
            return true;
        }
        else {
            if(fast->next !=NULL) {
                
            
            slow = slow->next;
            fast = fast->next->next;
        }
            else break;
        }
    }
    }

    return false;   
    }