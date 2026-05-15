 #include <bits/stdc++.h>
 using namespace std;
 class Node {
    public :
    int val;
    Node* left;
    Node* right;
    Node (int val) {
        this -> val = val;
        this -> left = this -> right = NULL;
    }

 };
 
 int main () {
    Node *a = new Node (1); // root
    Node* b = new Node (2);
    Node* c = new Node (3);
    Node* d = new Node (4);
    Node* e = new Node (5);
    Node* f = new Node (6);
    a -> left = b;
    a -> right = c;
    b -> left = d;
    b-> right = e;
    e -> left = f;
    // predeccssr
    Node* root = a;
    if(root -> left) {
    Node* temp = root-> left;
    while (temp -> right) temp = temp -> right;
    cout << "predecssr is " << temp -> val;
    }
    else cout << " No predecessr" << endl;
    // succssr
    if(root -> right) {
        Node* temp = root -> right;
        while (temp -> left) temp = temp -> left;
        cout << " succssr is " << temp -> left;  
    }
    else cout << " no succssr " ;
  
 }