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
void displayBFS (Node* root) {
    if (root == NULL) return;
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp -> val << " ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp -> right) q.push(temp -> right);
    }
    cout << endl;
}
int main() {
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* root = createTree (arr);
     displayBFS(createTree(arr));
}