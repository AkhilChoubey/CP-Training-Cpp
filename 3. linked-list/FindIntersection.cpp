#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        
        int count1 = 0, count2 = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
      
        ListNode *dummy1 = headA;
        ListNode *dummy2 = headB;
        
        while(temp1 != NULL){
            count1++;
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL){
            count2++;
            temp2 = temp2->next;
        }
        
        int diff = abs(count1-count2);
        
        while(diff--){
            if(count1 >= count2) {
                headA = headA->next;
            }
            else {
                headB = headB->next;
            }
        }
        
        while(headA != NULL &&headB != NULL){
            if(headA == headB){
                
                return headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }

    int main(){

    }