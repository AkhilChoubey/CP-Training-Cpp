#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// example --   1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1
// Logic :: we will first traverse through mid of list (using slow, fast * approach)
//          then we will reverse from mid to size_of_list , then we will compare the --> 1->2->3->4->1->2->3
//          reversed list will starting node .

ListNode* reverseList(ListNode *head) {
    if(head == NULL && head->next == NULL) {
        return head;
    }

    ListNode* pre = NULL, *cur = head, *next = NULL;

    while(cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = cur->next;
    }

    return pre;
}

ListNode* findMid(ListNode *head) {

    ListNode* slow = head, *fast = head;

    while( fast != NULL && fast->next != NULL ) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
} 

bool PalindromeLinkedList(ListNode *head) {
    
    if(head == NULL || head->next == NULL) {
        return true;
    } 
    //Linked List have more than 1 element.

    ListNode *mid = findMid(head);
    ListNode *revList = reverseList(mid);

    ListNode *temp = head;
    while(revList != NULL) {
        if(temp->val != revList->val) {
            return false;
        }
        temp = temp->next;
        revList = revList->next;
    }
    return true;
}


int main() {

}