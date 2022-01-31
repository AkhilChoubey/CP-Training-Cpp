#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    // implementation of DLL VERY EASILY

    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    int cap;

    //Creating head and tail
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node *> mi;

    //ADD NODE FUNCTION 1->3 === 1->2->3   INT O(1);
    // add always at head next;

    void addNode(node *newNode)
    {
        node *next = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = next;
        next->prev = newNode;
    }
    // DELETE NODE FUNTION  1->2->3  ===    1->3;// DELETE IN O(1);
    // always delete prev of tail

    void deleteNode(node *delNode)
    {
        node *delprev = delNode->prev;
        node *delnext = delNode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    LRUCache(int capacity)
    {
        // ADDED CAPACITY AND JOINED HEAD AND TAIL INITIALLY
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_)
    {
        //CASE 1
        if (mi.find(key_) != mi.end())
        {
            //we will take the value of old node and delete it then we will add same value node at front
            node *oldnode = mi[key_];
            int value = oldnode->val;
            mi.erase(key_);
            deleteNode(oldnode);
            addNode(oldNode);
            mi[key_] = head->next; //as it is added to next of head always to keep it in front
            return value;
        }
        //CASE 2
        return -1;
    }

    void put(int key_, int val)
    {
        //CASE 1
        if (mi.find(key_) != mi.end())
        {
            node *oldnode = mi[key_];
            mi.erase(key_);
            deleteNode(oldnode);
        }
        //CASE 2
        if (mi.size() == cap)
        {
            mi.erase(tail->prev->val);
            deleteNode(tail->prev);
        }

        addNode(new node(key_, val));
        mi[key_] = head->next; // AS ADDED AT NEXT TO HEAD ALWAYS;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
