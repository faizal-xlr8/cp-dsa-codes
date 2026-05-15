#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this ->val = val;
        left = right = NULL;
    }
};
bool isLeaf(Node* root) {
    if(root == NULL) return false;
    return !root -> left && !root -> right;
}
void leftBoundary(vector <int> &arr, Node* root) {
 if(root == NULL) return;
 
 Node* curr = root -> left;
 while (true) {
    if(!isLeaf(curr)) arr.push_back(curr -> val);
    else break;
    if(curr -> left) curr = curr -> left;
    else curr = curr -> right;
 }
}
void leafNode(vector <int> &arr, Node* root) {
if(root == NULL) return;
if (root -> left == NULL && root-> right == NULL) arr.push_back(root -> val);
leafNode(arr,root -> left);
leafNode(arr,root -> right);
}
void rightBoundary(vector <int> &arr, Node* root) {
 stack<int> st;
 Node* curr = root -> right;
 while (true) {
    if(!isLeaf(curr)) st.push(curr -> val);
    else break;
    if(curr -> right) curr = curr -> right;
    else curr = curr -> left;
 }
    while(!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }
}
void displayBoundary(Node* root) {
    vector <int> arr;
    arr.push_back(root ->val);
    if(isLeaf(root)) return;
    leftBoundary(arr, root);
    leafNode(arr, root);
    rightBoundary(arr, root);
    for (int i = 0; i < arr.size(); ++i) cout << arr[i] <<" ";
    cout << endl;
}
Node* createTree(vector<int> &arr) {
    Node* root = new Node(arr[0]);
    int i = 1;
    int j = 2;
    queue <Node*> q;
    q.push(root);
    int n = arr.size();
    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();
        if(arr[i]) temp -> left = new Node(arr[i]);
        else temp->left = NULL;
        if(j != n && arr[j]) temp -> right = new Node(arr[j]);
        else temp -> right = NULL;
        if(temp->left) q.push(temp->left);
        if(temp -> right) q.push(temp -> right);
        i += 2;
        j += 2;
    }
    return root;
}
int main() {
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* root = createTree (arr);
    displayBoundary(root);
}