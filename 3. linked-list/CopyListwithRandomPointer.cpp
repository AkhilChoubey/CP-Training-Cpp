#include<bits/stdc++.h>
using namespace std;

// We are given with a New type of linked list , we need to find copy of given list
// and return the head node of new list, we need to do deap copy : copied at new address

class Node {
    public:
        int val;
        Node *next;
        Node *random;
}

Node* copy(Node *head) {
    if(head == NULL) {
        return head;
    }
        Node *ptr = head, *qtr = NULL;

        //Inserting newNode between ptr and qtr , then incrementing ptr to qtr
        while(ptr != NULL) {

            qtr = ptr->next;
            Node* newNode = new Node(ptr->val);
            newNode->next = qtr;
            ptr->next = newNode;
            ptr = qtr;
        }
    

    //Setting the random pointer
    ptr = head; 
    qtr = head->next;

    while(ptr !=NULL && ptr->next != NULL) {
        qtr = ptr->next;
        if(ptr->random != NULL) {
            qtr->random = ptr->random->next;
        }
        else {
            qtr->random = NULL;
        }
        ptr = qtr->next;
    }

    Node *newHead = head->next;
    ptr = head;

    while(ptr != NULL && ptr->next != NULL) {
        qtr = ptr->next;
        ptr->next = qtr->next;
        ptr = qtr; 
    }

    return newHead;

}