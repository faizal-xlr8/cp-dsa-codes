// C++ Program to Find distance between 
// two nodes of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;  
    Node* left;
    Node* right;

    Node(int key) {
        data = key;  
        left = nullptr; 
        right = nullptr;
    }
};
 //
   
    // Create a sample tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7 
    //  /     \
    //  8      9
 int findLevel (Node* root, Node* target, int level) {
     if (root == NULL) {
        level = -1;
        return level;
     }
     if (root -> data == target -> data) return level;
    //  if (root -> data < target -> data) findLevel (root -> left, target, level + 1);
    //  else findLevel (root -> right, target, level + 1);
     int left = findLevel (root -> left, target, level + 1);
     if (left == - 1)
     return findLevel(root -> right, target, level + 1);
     return left;
   // return level;
 }
bool exists (Node* root, Node* target) {
  if (root == NULL) return false;
  if(root -> data == target -> data) return true;
  return exists(root -> left, target) || exists (root -> right,target);
}
Node* findLCA (Node* root, int a, int b) {
  Node* aRoot  = new Node(a);
  Node* bRoot = new Node(b);
  if (root -> data == a || root -> data == b) return root;
  		if (exists(root ->left, aRoot) && exists(root ->right, bRoot)) return root;
      if (exists(root ->left, bRoot) && exists(root ->right, aRoot)) return root;
  		if (exists(root ->left,  aRoot) && exists (root -> left, bRoot)) return findLCA(root -> left, a, b);
		if (exists(root ->right, aRoot) && exists (root -> left, bRoot)) return findLCA(root -> right, a, b);
}
// Function to find distance between two 
// nodes in a binary tree
int findDistance(Node* root, int a, int b) {
   //concept is to find LCA and then we add levels from that LCA to node1 and node2
  Node* rootLCA = findLCA (root, a, b); // LCA mil jayega
    Node* aRoot  = new Node(a);
  Node* bRoot = new Node(b);
  int leftDistance = findLevel( rootLCA , aRoot , 0);
  int rightDistance = findLevel (rootLCA, bRoot, 0);
  return leftDistance + rightDistance;
  
}

int main() {
  
    // Create a sample tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7 
    //  /     \
    //  8      9

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left -> left = new Node(8);
    root -> left -> right -> right = new Node(9);

    cout << findDistance(root, 8, 9) << endl;

    return 0;
}