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
 void displayTree(Node* root) {
    if (root == NULL) return;
    cout << root -> val << " ";
    displayTree (root -> left ); //printing all he left nodes 
    displayTree (root -> right); // print all the right
 }
 int sum (Node * root) {
    if (root == NULL) return 0;
    return root -> val + sum (root -> left) + sum (root -> right);
 }
 int size (Node* root) {
    if (root == NULL) return 0;
    return 1 + size(root -> left) + size (root -> right);
 }
 int maxi (Node* root) {
    // base case
    if (root == NULL) return INT_MIN;
    //for the sake of simplicity
    // int lMax = maxi (root -> left);
    // int rMax = maxi (root -> right);
    // return max (root -> val, max(lMax, rMax));
    return max (root -> val, max(maxi(root -> left),maxi(root -> right)));
 }
 int product (Node * root) {
    if (root == NULL) return 1;
    return root -> val * product(root -> left) * product (root -> right);
 }
 int level (Node* root) {
    if (root == NULL) return 0;
     int lMax = level (root -> left);
    int rMax = level (root -> right);
    return 1 + max (lMax, rMax);
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
    displayTree (a);
    cout << sum(a) << endl;
    cout << size(a) << endl;
    cout << maxi (a) << endl;
    cout << product (a) << endl;
    cout << level(a) << endl;
 }