#include <iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/* --------------- Implement here --------------- */

void inorderTraversal(TreeNode *root)
{
    /* Exercise 3a) */
}

int maxDepth(TreeNode *root)
{
    /* Exercise 3b) */
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    /* Exercise 3c) */
}

/* ---------------------------------------------- */


/* ---------- Test Code. Do not change ---------- */ 
int main()
{
    // Constructing a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Find the maximum depth of the tree
    int depth = maxDepth(root);
    cout << "Maximum Depth: " << depth << endl;

    // Find the lowest common ancestor of nodes 4 and 5
    TreeNode* lca = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << "Lowest Common Ancestor of 4 and 5: " << (lca ? lca->val : -1) << endl;

    return 0;
}
