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
  void displayBFS (Node* root)
 {
          // base case
          if (root == NULL ) return;
          queue <Node*> q;
          q.push(root); 
          while (!q.empty()) {
            Node* temp = q.front();
            cout << temp -> val << " ";
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
              cout << endl; 
          }     
          cout << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
 }
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
    displayBFS(a);
 }