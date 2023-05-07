#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        // Reach the leftmost node of the current subtree
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Backtrack to the parent node while processing the nodes
        current = st.top();
        st.pop();
        cout << current->val << " ";

        // Move to the right child
        current = current->right;
    }
}

int main() {
    
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    TreeNode* root = nullptr;

    
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
    }

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

   

    return 0;
}