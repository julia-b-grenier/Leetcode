/**
 * Definition for a binary tree node.
 * 
 */
#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::vector<int> response;
        postOrder(root->left, response);
        preOrder(root->right, response);
        
        return response.size() == 0;
    }
    
    void postOrder(TreeNode* node, std::vector<int>& response) {
        if (node == nullptr) {
            std::cout << "Adding Null " << std::endl;
            response.push_back(INT_MIN);
            return;
        }
        // Traverse the left subtree
        postOrder(node->left, response);
        // Traverse the right subtree
        postOrder(node->right, response);
        // Visit the current node
        response.push_back(node->val);
        std::cout << "Visiting node " << std::to_string(node->val) << std::endl;
    }
    
    void preOrder(TreeNode* node, std::vector<int>& response) {
        if (node == nullptr) {
            if (INT_MIN == response.back()) {
                std::cout << "Removing Null " << std::endl;
                // Remove node
                response.pop_back();
            }
            return;
        }
        
        std::cout << "Comparing node " << std::to_string(node->val) << " with last element in response list " << response.back() << std::endl;
        if (node->val == response.back()) {
            // Remove node
            response.pop_back();
            
            // Traverse the left subtree
            preOrder(node->left, response);
            
            // Traverse the right subtree
            preOrder(node->right, response);
        }
    }
};

int main() {
    TreeNode a;
    a.val = 2;
    TreeNode b;
    b.val = 3;
    TreeNode branchLeft;
    branchLeft.val = 1;
    // branchLeft.left = &a;
    branchLeft.right = &b;
    TreeNode branchRight;
    branchRight.val = 1;
    // branchRight.left = &b;
    branchRight.right = &a;

    TreeNode root;
    root.val = 0;
    root.left = &branchLeft;
    root.right = &branchRight;

    Solution sol;
    bool result = sol.isSymmetric(&root);
    std::cout << "Answer " << (result ? "True" : "False");

    return 0;
}