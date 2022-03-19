#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
private:
    void reorder_cache(int key){
        //push the key node to the head
        
        if(head->key == key)
            return;
                
        Node *tmp = mp[key];
            
        //merge the holed chain
        if(tmp != tail){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }else{                
            tmp->prev->next = NULL;
            tail = tmp->prev;
        }
            
        //move the key node before the head
        tmp->prev = NULL;
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    
public:
    LRUCache(int capacity){
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    
    virtual void set(int key, int val){
        //check if key is in cache
        if(get(key) == -1){
            //insert new node before the head
            Node *n = new Node(NULL, head, key, val);
        
            head = n;
            
            if(head->next != NULL)
                head->next->prev = head;
            else //if first element
                tail = head;
            
            //map the new node
            mp[key] = n;
            
            //check for capacity overflow
            if(mp.size() > cp){
                //delete the tail element
                mp.erase(tail->key);
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
        }else{
            //the key value is present in cache
            //update the mapped value
            mp[key]->value = val;
            
            //update the order of cache elements
            reorder_cache(key);
        }
    }
    
    virtual int get(int key){
        if(mp[key] == NULL)
            return -1;
        
        //reorder_cache(key);
            
        return mp[key]->value;    
    }
    
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
