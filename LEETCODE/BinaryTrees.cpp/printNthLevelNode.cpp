#include <bits/stdc++.h>
using namespace std;
class Node{
    public :
    Node* left;
    Node* right;
    int val;
    Node (int val) {
        this -> val = val;
        left = right = NULL;
    }
};

void printLevel(Node* root, int level, int k) {
    if (level > k) return; // this to ensure if calls starts from level > k we dont do anything just return back
 if (level == k) {
    cout << root -> val << " ";
    return;
 }
 printLevel (root -> left, level + 1, k);
 printLevel (root -> right, level + 1, k);

}
int calculateLevel (Node* root) {
    if (root == NULL) return 0;
    return 1 + max(calculateLevel (root -> left) ,calculateLevel(root -> right)); 
}
int main() {
    Node* a = new Node (1); // root
    Node* b = new Node (2);
    Node* c = new Node (3);
    Node* d = new Node (4);
    Node* e = new Node (5);
    Node* f = new Node (6);
    Node* g = new Node (7); 
    a -> left = b;
    a -> right = c;
    b -> left = d;
    b-> right = e;
    e -> left = f;
    c -> left = g;
    // int k = 3;
    // printLevel (a, 1, 3);
    int levelTotal = calculateLevel (a);
    for (int i = 1; i <= levelTotal; ++i) {
        printLevel (a, 1, i);
        cout << endl;
    }
}