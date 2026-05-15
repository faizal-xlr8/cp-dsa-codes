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
void topView(Node* root) {
   map<int, int> m; // represnt level, value ....level = X axis on tree 
    //point is we are using map only to keep elements stored which are our point of interest
    queue <pair<int, Node*>> q;  // represents  level, Node -> val
    // concept is we will do level order traversal using a queue and insert
    //elements  in the map only when we have no treeNode with that level
    //already inserted in the map
    // pair <int,Node*> p;
    // p.first = 0;
    // p.second = root;//mark on the number line
    q.push({0,root});
    while (!q.empty()) {
       int level = q.front().first;
       Node* temp = q.front().second;//this is the mark on number line
            q.pop();
        if (m.find(level)== m.end()) { // element not found
            m[level] = temp -> val;
        }
        if(temp -> left) {
            // pair <int, Node*> p;
            // p.first = level - 1;
            // p.second = temp -> left;
            q.push({level - 1, temp ->left});

        }
        if (temp -> right) {
            // pair <int, Node*> t;
            // t.first = level + 1;
            // t. second= temp -> right;
            
            q.push({level + 1, temp -> right});
        }
       

    }
    // int minLevel = INT_MAX;
    // int maxLevel = INT_MIN;
    // for (auto x : m) {
    //     minLevel = min(minLevel, x.first);
    //     maxLevel = max (maxLevel, x.first);
    // }
    // for (int i = minLevel; i <= maxLevel; ++i) {
    //     cout << m[i] << " ";
    // }
    for (auto x : m) cout << m[x.first] <<" "; //  prints values of map in ascending value of keys
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
    vector <int> arr = {1, 2, 3, 4, 5,'\0',6, '\0', 7, 8};
    Node* root = createTree (arr);
     displayBFS(createTree(arr));
     topView(root);
}