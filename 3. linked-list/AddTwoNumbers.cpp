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
        sum = (p == NULL)? 0 : p->val + (q == NULL)? 0 : q->val + carry;
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

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }

    ListNode* ptr1 = a, *ptr2 = b;

    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    int sum = 0, carry = 0;

    while(ptr1 != NULL || ptr2 != NULL || carry) {
        if(ptr1 != NULL) {
            sum += ptr1->val;
            ptr1 = ptr1->next;
        }
        if(ptr2 != NULL) {
            sum += ptr2->val;
            ptr2 = ptr2->next;
        }

        sum += carry;
        carry = sum/10;
        sum = sum%10;

        temp->next = new ListNode(sum);
        temp = temp->next;
    }

    return dummy->next;
}