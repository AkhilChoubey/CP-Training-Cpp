#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseListInKGroups(ListNode* head, int K) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *dummy = head;
    int count = 0;
    while(dummy != NULL) {
        count++;
        dummy = dummy->next;
    }

    int k = 0;
    ListNode *pre = NULL, *cur = head, *next = NULL;

    while(cur != NULL && k < K) {
        k++;
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = cur->next;
    }

    if( next != NULL) {
       head->next = reverseListInKGroups(next, K);
    }
    else {
        head->next = cur;
    }

    return pre;
}