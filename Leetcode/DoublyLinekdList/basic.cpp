#include <bits/stdc++.h>
using namespace std;
class Node {
    public :
    int val;
    Node* next;
    Node* prev;
    Node() {}
    Node (int val) {
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
 
};
class Dll {
    public : 
    Node* head;
    Node* tail;
    int size;
    // default constructor
    Dll () {
        head = tail = NULL;
        size = 0;
    }
    void addAtBeginning (int val) {
        Node* newNode = new Node (val);
        if (head == NULL) head =tail =  newNode;
        else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        }
        size ++;
    }
    void addAtEnd(int val) {
        Node* newNode = new Node (val);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
        Node* temp = head;
        while (temp -> next) {
            temp = temp -> next;
        }
   
        temp -> next = newNode;
        newNode -> prev = temp;
       tail = newNode;
        size ++;
            }
    }
    void addAtIndex (int idx, int val) {

        if (idx == 0) return addAtBeginning (val) ;
        if (idx == size)return addAtEnd (val);
        Node* temp = head;
        for (int i = 1; i < idx; ++i) {
            temp = temp -> next ;

        } 
        Node* newNode = new Node (val);
        newNode -> next = temp -> next;
        temp -> next -> prev = newNode;
        temp -> next = newNode;
        newNode -> prev = temp;
        size++;
    } 
    void deleteAtHead() {
        if(head -> next == NULL) {
            head = head -> next; 
            tail = NULL;
            return;
        }
        head = head -> next; 
        head  -> prev = NULL; 
    }
    void deleteAtTail() {
        if (head == NULL) return;
        if(head -> next == NULL) {
            head = head -> next; 
            tail = NULL;
            return;
        }
       tail = tail -> prev;
        // Node* temp = head;
        // while (temp -> next -> next) {
        //     temp = temp -> next;
        // }
        //  tail = temp;
        tail -> next = NULL;
        size--;
    }
    void deleteAt(int idx) {
        if (head == NULL) return;
        if (idx == 0) return deleteAtHead();
        if (idx == size - 1) return deleteAtTail();
           
        Node* temp = head;
        for (int i = 1; i < idx; ++i) {
        temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        temp -> next -> prev = temp;
        size --;
    }
    void displayList () {
        Node* temp = head;
        while (temp) {
            cout << temp -> val << " ";
            temp = temp -> next;
        
        }
        cout << endl;
    }
  
};
void display (Node* head ) {
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
void displayRev (Node* tail) {
    while (tail) {
        cout << tail -> val  << " ";
        tail = tail -> prev;
    }
    cout << endl;
}

int main () {
    // Node *a = new Node(10);
    // Node *b = new Node (20);
    // Node* c = new Node (30);
    // Node* d = new Node (40);
    // a -> next = b;
    // b -> next = c;
    // c -> next = d;
    // b -> prev = a;
    // c -> prev = b;
    // d -> prev = c;
    // display(a);
    // displayRev(d);
    Dll* list = new Dll();
    list -> addAtBeginning(10);
    list -> addAtBeginning(20);
    list -> addAtBeginning(30);
    list -> addAtBeginning(40);
    list -> displayList();
    list -> deleteAtHead();
    list -> displayList();
    list -> deleteAtTail();
    list -> displayList();
    
    
}