#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        cout << current->val << " ";

        if (current->right != nullptr) {
            st.push(current->right);
        }
        if (current->left != nullptr) {
            st.push(current->left);
        }
    }
}

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

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    

    return 0;
}
