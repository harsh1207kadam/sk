#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

public:
 TreeNode* root;
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertIntoBST(root, val);
    }

    int countNodes() {
        return countNodes(root);
    }

    int getHeight() {
        return getHeight(root);
    }

    void mirrorImage() {
        mirrorImage(root);
    }

private:
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insertIntoBST(node->left, val);
        } else {
            node->right = insertIntoBST(node->right, val);
        }

        return node;
    }

    void inorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

    int countNodes(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int count = 1;
        count += countNodes(node->left);
        count += countNodes(node->right);

        return count;
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    void mirrorImage(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        swap(node->left, node->right);

        mirrorImage(node->left);
        mirrorImage(node->right);
    }

    
};

int main() {
    BST bst;

    int choice;
    int val;

    while (true) {
        cout << "BST Operations:" << endl;
        cout << "1. Insert into BST" << endl;
        cout << "2. Count the number of nodes" << endl;
        cout << "3. Get the height of BST" << endl;
        cout << "4. Get the mirror image of BST" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> val;
                bst.insert(val);
                cout << "Value inserted into BST." << endl;
                break;
            case 2:
                cout << "Number of nodes in BST: " << bst.countNodes() << endl;
                break;
            case 3:
                cout << "Height of BST: " << bst.getHeight() << endl;
                break;
            case 4:
                bst.mirrorImage();
                cout << "Mirror image of BST created." << endl;
               // bst.inorder();
               
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
