#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node (int val) {
        this -> val = val;
        this -> right = NULL;
        this -> left = NULL;
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
void  displayPre(Node* root) {
    if (root == NULL) return;
    stack <Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        cout << temp -> val << " ";
        if(temp -> right) st.push(temp -> right);
        if(temp->left) st.push(temp ->left);
    }
    cout << endl;
}
void displayInorder (Node* root){
    stack <Node*> st;
   
    Node* curr = root;
    while(curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr -> left;  
        }
        // curr is at null at left part
        Node* temp = st.top();
        cout << temp -> val <<" ";
        st.pop();
        curr = temp -> right;
    }
    cout << endl;
}

void postOrder (Node* root, vector <int> &ans) {
    // iterative
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* temp = st.top();
        ans.push_back(temp -> val);
        st.pop();
        if(temp -> left) st.push(temp -> left);
        if(temp -> right) st.push(temp -> right);

    }
    reverse (ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] <<" ";
    cout << endl;
}
int main() {
     vector <int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = createTree (arr);
vector <int> ans;
    displayPre(root);
    postOrder(root, ans);
    displayInorder(root);
    
}