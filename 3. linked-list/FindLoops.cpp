#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// The algo known as floyd slow fast pointer approach , 
// when slow pointer enters the loop , fast pointer was already in the loop 
// and after every iteration there distance will increase by one , 
// when there distance will become n (size of loop) , they will meet.

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
                if(fast->next != NULL) {       
                    slow = slow->next;
                    fast = fast->next->next;
                }
                else break;
            }
        }
    }

    return false;   
}


// O(n^2) solution
// First write this solution **after this method use map instead of vector

bool findLoops(ListNode* head) {
    if(head == NULL) {
        return false;
    } 
    vector<ListNode*> arr;

    ListNode* temp = head;

    while(temp != NULL) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == temp->next) {
                return true;
            }
        }
         arr.push_back(temp);
         temp = temp->next;

    }
    return false;
}

// method 3 : using map to store next pointer of each node
bool findLoops(ListNode* head) {
    if(head == NULL) {
        return false;
    } 
    // vector<ListNode*> arr;
    map<ListNode*, ListNode*> m;

    ListNode* temp = head;

    while(temp != NULL) {
        // for(int i = 0; i < arr.size(); i++) {
            if(m.find(temp) != m.end()) {
                return true;
            }
        // }
        //  arr.push_back(temp);
        m[temp] = temp->next;
         temp = temp->next;

    }
    return false;
}