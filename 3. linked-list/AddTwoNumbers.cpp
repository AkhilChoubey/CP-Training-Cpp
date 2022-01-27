#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    if(a == NULL) {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    //both a and b are not NULL.
    ListNode dummy(0);
    ListNode *p = a, *q = b, *r = &dummy;

    int sum = 0, carry = 0;
    while (p != NULL || q != NULL)
    {
        sum = (p == NULL)? 0 : p->val + (q == NULL)? 0 : q->val;
        carry = sum / 10;
        sum = sum % 10;
        r->next = new ListNode(sum);
        r = r->next;

        if(p != NULL) p = p->next;
        if(q != NULL) q = q->next;
    }

    if(carry > 0) {
        r->next = new ListNode(carry);
    }

    return dummy.next;
    
    
}