#include <iostream>

using namespace std;
class Tree;
class TreeNode{
    friend class Tree;
    private:
    TreeNode* leftChild;
    char data;
    TreeNode* rightChild;
};

class Tree{
    public:
    int size() const;
    bool empty() const;

    private:
    TreeNode* root;
};